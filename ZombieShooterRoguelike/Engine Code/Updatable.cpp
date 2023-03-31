#include "Updatable.h"

#include <cassert>

#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"
#include "SceneManager.h"
#include "Scene.h"

Updatable::Updatable()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new UpdateRegistrationCommand(this)),
	pDeregCmd(new UpdateDeregistrationCommand(this)),
	deleteRef()
{
	// do nothing
}

Updatable::Updatable(const Updatable& u)
	: regState(u.regState),
	pRegCmd(new UpdateRegistrationCommand(*u.pRegCmd)),
	pDeregCmd(new UpdateDeregistrationCommand(*u.pDeregCmd)),
	deleteRef()
{
	// do nothing
}

Updatable& Updatable::operator=(const Updatable& u)
{
	regState = u.regState;
	pRegCmd = new UpdateRegistrationCommand(*u.pRegCmd);
	pDeregCmd = new UpdateDeregistrationCommand(*u.pDeregCmd);

	return *this;
}

Updatable::~Updatable()
{
	delete pDeregCmd;
	delete pRegCmd;
}

void Updatable::EnqueueForUpdateRegistration()
{
	assert(regState == RegistrationState::CurrentlyDeregistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pRegCmd);

	regState = RegistrationState::PendingRegistration;
}

void Updatable::EnqueueForUpdateDeregistration()
{
	assert(regState == RegistrationState::CurrentlyRegistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pDeregCmd);

	regState = RegistrationState::PendingDeregistration;
}

void Updatable::RegisterForUpdate()
{
	assert(regState == RegistrationState::PendingRegistration);

	deleteRef = SceneManager::GetCurrentScene()->Register(this);

	regState = RegistrationState::CurrentlyRegistered;
}

void Updatable::DeregisterForUpdate()
{
	assert(regState == RegistrationState::PendingDeregistration);

	SceneManager::GetCurrentScene()->Deregister(deleteRef);

	regState = RegistrationState::CurrentlyDeregistered;
}
