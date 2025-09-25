#include "DrawObject.h"

#include <cassert>

#include "TDrawRegistrationCommand.h"
#include "TDrawDeregistrationCommand.h"
#include "SceneManager.h"
#include "Scene.h"

DrawObject::DrawObject()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new TDrawRegistrationCommand(this)),
	pDeregCmd(new TDrawDeregistrationCommand(this)),
	deleteRef()
{
	// do nothing
}

DrawObject::~DrawObject()
{
	delete pDeregCmd;
	delete pRegCmd;
}

void DrawObject::EnqueueForDrawRegistration()
{
	assert(regState == RegistrationState::CurrentlyDeregistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pRegCmd);

	regState = RegistrationState::PendingRegistration;
}

void DrawObject::EnqueueForDrawDeregistration()
{
	assert(regState == RegistrationState::CurrentlyRegistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pDeregCmd);

	regState = RegistrationState::PendingDeregistration;
}

void DrawObject::RegisterForDraw()
{
	assert(regState == RegistrationState::PendingRegistration);

	deleteRef = SceneManager::GetCurrentScene()->Register(this);

	regState = RegistrationState::CurrentlyRegistered;
}

void DrawObject::DeregisterForDraw()
{
	assert(regState == RegistrationState::PendingDeregistration);

	SceneManager::GetCurrentScene()->Deregister(deleteRef);

	regState = RegistrationState::CurrentlyDeregistered;
}
