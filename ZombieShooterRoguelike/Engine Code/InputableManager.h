#ifndef INPUTABLE_MANAGER_H
#define INPUTABLE_MANAGER_H

#include <map>

#include <SFML/Window/Keyboard.hpp>

#include "KeyListener.h"

// forward declarations
class Inputable;

class InputableManager
{
public:
	InputableManager();
	InputableManager(const InputableManager& im) = delete;
	InputableManager& operator=(const InputableManager& im) = delete;
	virtual ~InputableManager();

	KeyListener::NotifyListPos Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, Inputable* pInputable);
	void Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos listPos);

private:
	using KeyTracker = std::map<sf::Keyboard::Key, KeyListener*>;

private:
	KeyTracker keyTracker;
};

#endif