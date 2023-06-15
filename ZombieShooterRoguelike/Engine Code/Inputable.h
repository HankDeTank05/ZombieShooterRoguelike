#ifndef INPUTABLE_H
#define INPUTABLE_H

#include <map>

#include "SFML/Window/Keyboard.hpp"

#include "RegistrationState.h"
#include "KeyEvent.h"

// forward declarations
class InputRegistrationCommmand;
class InputDeregistrationCommand;

class Inputable
{
public:
	Inputable();
	Inputable(const Inputable& i) = delete;
	Inputable& operator=(const Inputable& i) = delete;
	virtual ~Inputable();

protected:
	virtual void KeyPressed(sf::Keyboard::Key key);
	virtual void KeyReleased(sf::Keyboard::Key key);

	void EnqueueForInputRegistration(sf::Keyboard::Key key, KeyEvent eventToRegFor);
	void EnqueueForInputDeregistration(sf::Keyboard::Key key, KeyEvent eventToDeregFor);

public:
	void RegisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToRegFor);
	void DeregisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToDeregFor);

	struct RegistrationData
	{
		RegistrationState regState;
		InputRegistrationCommmand* pRegCmd;
		InputDeregistrationCommand* pDeregCmd;
	};

	using KeyTrackerID = std::pair<sf::Keyboard::Key, KeyEvent>;
	using KeyRegStateTracker = std::map<KeyTrackerID, RegistrationData>;

private:
	KeyRegStateTracker keyRegStateTracker;
};

#endif