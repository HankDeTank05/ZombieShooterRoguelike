#include "Inputable.h"

#include <cassert>

#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"
#include "SceneManager.h"
#include "Scene.h"

Inputable::Inputable()
	: keyRegStateTracker()
{
	// do nothing
}

void Inputable::KeyPressed(sf::Keyboard::Key key)
{
	// do nothing
}

void Inputable::KeyReleased(sf::Keyboard::Key key)
{
	// do nothing
}

void Inputable::EnqueueForInputRegistration(sf::Keyboard::Key key, KeyEvent eventToRegFor)
{
	KeyTrackerID keyID = KeyTrackerID(key, eventToRegFor);

	if (keyRegStateTracker.find(keyID) == keyRegStateTracker.end()) // if keyID not already in map
	{
		RegistrationData regData;
		regData.regState = RegistrationState::CurrentlyDeregistered;
		regData.pRegCmd = new InputRegistrationCommand(this, key, eventToRegFor);
		regData.pDeregCmd = new InputDeregistrationCommand(this, key, eventToRegFor);

		keyRegStateTracker.insert(std::pair<KeyTrackerID, RegistrationData>(keyID, regData));
	}
	else
	{
		assert(keyRegStateTracker[keyID].regState == RegistrationState::CurrentlyDeregistered);
	}

	SceneManager::GetCurrentScene()->EnqueueCommand(keyRegStateTracker[keyID].pRegCmd);

	keyRegStateTracker[keyID].regState = RegistrationState::PendingRegistration;
}

void Inputable::EnqueueForInputDeregistration(sf::Keyboard::Key key, KeyEvent eventToDeregFor)
{
	KeyTrackerID keyID = KeyTrackerID(key, eventToDeregFor);

	// there should already be an entry in the map for this
	assert(keyRegStateTracker.find(keyID) != keyRegStateTracker.end());

	assert(keyRegStateTracker[keyID].regState == RegistrationState::CurrentlyRegistered);

	SceneManager::GetCurrentScene()->EnqueueCommand(keyRegStateTracker[keyID].pDeregCmd);

	keyRegStateTracker[keyID].regState = RegistrationState::PendingDeregistration;
}

void Inputable::RegisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToRegFor)
{
	SceneManager::GetCurrentScene()->Register(key, eventToRegFor, this);
}

void Inputable::DeregisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToDeregFor)
{
	// get the listPos for deregistration
	KeyTrackerID keyID = KeyTrackerID(key, eventToDeregFor);
	KeyListener::NotifyListPos listPos = keyRegStateTracker[keyID].listPos;

	SceneManager::GetCurrentScene()->Deregister(key, eventToDeregFor, listPos);
}
