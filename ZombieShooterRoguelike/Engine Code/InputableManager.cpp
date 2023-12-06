#include "InputableManager.h"

#include "KeyListener.h"
#include <cassert>

InputableManager::InputableManager()
	: keyTracker()
{
	// do nothing
}

KeyListener::NotifyListPos InputableManager::Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, Inputable* pInputable)
{
	if (keyTracker.count(key) == 0)
	{
		keyTracker.emplace(key, new KeyListener(key));
	}

	return keyTracker[key]->Register(eventToRegFor, pInputable);
}

void InputableManager::Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos listPos)
{
	assert(keyTracker.count(key) > 0);

	keyTracker[key]->Deregister(eventToDeregFor, listPos);
}
