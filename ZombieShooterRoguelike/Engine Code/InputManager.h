#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <map>

#include <SFML/Window/Keyboard.hpp>

#include "KeyListener.h"

// forward declarations
class InputObject;

class InputManager
{
public:
	InputManager();
	InputManager(const InputManager& im) = delete;
	InputManager& operator=(const InputManager& im) = delete;
	virtual ~InputManager();

	KeyListener::NotifyListPos Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, InputObject* pInputable);
	void Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos listPos);

private:
	using KeyTracker = std::map<sf::Keyboard::Key, KeyListener*>;

private:
	KeyTracker keyTracker;
};

#endif