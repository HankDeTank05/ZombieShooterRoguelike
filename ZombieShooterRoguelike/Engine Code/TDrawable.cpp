#include "TDrawable.h"

#include <cassert>

#include "TDrawRegistrationCommand.h"
#include "TDrawDeregistrationCommand.h"
#include "SceneManager.h"
#include "Scene.h"

TDrawable::TDrawable()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new TDrawRegistrationCommand(this)),
	pDeregCmd(new TDrawDeregistrationCommand(this)),
	deleteRef()
{
	// do nothing
}

TDrawable::~TDrawable()
{
	delete pDeregCmd;
	delete pRegCmd;
}

void TDrawable::EnqueueForDrawRegistration()
{
	assert(regState == RegistrationState::CurrentlyDeregistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pRegCmd);

	regState = RegistrationState::PendingRegistration;
}

void TDrawable::EnqueueForDrawDeregistration()
{
	assert(regState == RegistrationState::CurrentlyRegistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(pDeregCmd);

	regState = RegistrationState::PendingDeregistration;
}

void TDrawable::RegisterForDraw()
{
	assert(regState == RegistrationState::PendingRegistration);

	deleteRef = SceneManager::GetCurrentScene()->Register(this);

	regState = RegistrationState::CurrentlyRegistered;
}

void TDrawable::DeregisterForDraw()
{
	assert(regState == RegistrationState::PendingDeregistration);

	SceneManager::GetCurrentScene()->Deregister(deleteRef);

	regState = RegistrationState::CurrentlyDeregistered;
}
