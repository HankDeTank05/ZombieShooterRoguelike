#include "UpdateObject.h"

#include <cassert>

#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"
#include "SceneManager.h"
#include "Scene.h"

UpdateObject::UpdateObject()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new UpdateRegistrationCommand(this)),
	pDeregCmd(new UpdateDeregistrationCommand(this)),
	deleteRef()
{
	// do nothing
}

UpdateObject::UpdateObject(const UpdateObject& u)
	: regState(u.regState),
	pRegCmd(new UpdateRegistrationCommand(*u.pRegCmd)),
	pDeregCmd(new UpdateDeregistrationCommand(*u.pDeregCmd)),
	deleteRef()
{
	// do nothing
}

UpdateObject& UpdateObject::operator=(const UpdateObject& u)
{
	regState = u.regState;
	pRegCmd = new UpdateRegistrationCommand(*u.pRegCmd);
	pDeregCmd = new UpdateDeregistrationCommand(*u.pDeregCmd);

	return *this;
}

UpdateObject::~UpdateObject()
{
	delete pDeregCmd;
	delete pRegCmd;
}

void UpdateObject::EnqueueForUpdateRegistration()
{
	assert(regState == RegistrationState::CurrentlyDeregistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pRegCmd);

	regState = RegistrationState::PendingRegistration;
}

void UpdateObject::EnqueueForUpdateDeregistration()
{
	assert(regState == RegistrationState::CurrentlyRegistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pDeregCmd);

	regState = RegistrationState::PendingDeregistration;
}

void UpdateObject::RegisterForUpdate()
{
	assert(regState == RegistrationState::PendingRegistration);

	deleteRef = SceneManager::GetCurrentScene()->Register(this);

	regState = RegistrationState::CurrentlyRegistered;
}

void UpdateObject::DeregisterForUpdate()
{
	assert(regState == RegistrationState::PendingDeregistration);

	SceneManager::GetCurrentScene()->Deregister(deleteRef);

	regState = RegistrationState::CurrentlyDeregistered;
}
