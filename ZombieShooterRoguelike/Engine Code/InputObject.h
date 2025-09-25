#ifndef INPUT_OBJECT_H
#define INPUT_OBJECT_H

#include <map>

#include "SFML/Window/Keyboard.hpp"

#include "RegistrationState.h"
#include "KeyEvent.h"
#include "KeyListener.h"

// forward declarations
class InputRegistrationCommand;
class InputDeregistrationCommand;

class InputObject
{
public:
	InputObject();
	InputObject(const InputObject& i) = delete;
	InputObject& operator=(const InputObject& i) = delete;
	virtual ~InputObject();

protected:
	virtual void KeyPressed(sf::Keyboard::Key key);
	virtual void KeyReleased(sf::Keyboard::Key key);

	void EnqueueForInputRegistration(sf::Keyboard::Key key, KeyEvent eventToRegFor);
	void EnqueueForInputDeregistration(sf::Keyboard::Key key, KeyEvent eventToDeregFor);

private:
	friend class InputableAttorney;

	void RegisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToRegFor);
	void DeregisterForInputReading(sf::Keyboard::Key key, KeyEvent eventToDeregFor);

	struct RegistrationData
	{
		RegistrationState regState;
		InputRegistrationCommand* pRegCmd;
		InputDeregistrationCommand* pDeregCmd;
		KeyListener::NotifyListPos listPos;
	};

	using KeyTrackerID = std::pair<sf::Keyboard::Key, KeyEvent>;
	using KeyRegStateTracker = std::map<KeyTrackerID, RegistrationData>;

private:
	KeyRegStateTracker keyRegStateTracker;
};

#endif