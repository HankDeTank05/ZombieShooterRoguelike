#include "Inputable.h"

Inputable::Inputable()
	: keyRegStateTracker()
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
}
