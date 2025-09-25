#include "InputManager.h"

#include "KeyListener.h"
#include <cassert>

InputManager::InputManager()
	: keyTracker()
{
	// do nothing
}

InputManager::~InputManager()
{
	for (KeyTracker::iterator it = keyTracker.begin(); it != keyTracker.end(); it++)
	{
		if ((*it).second != nullptr)
		{
			delete (*it).second;
		}
	}
}

KeyListener::NotifyListPos InputManager::Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, InputObject* pInputable)
{
	if (keyTracker.count(key) == 0)
	{
		keyTracker.emplace(key, new KeyListener(key));
	}

	return keyTracker[key]->Register(eventToRegFor, pInputable);
}

void InputManager::Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos listPos)
{
	assert(keyTracker.count(key) > 0);

	keyTracker[key]->Deregister(eventToDeregFor, listPos);
}
