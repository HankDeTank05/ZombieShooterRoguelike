#include "KeyListener.h"
#include <cassert>

KeyListener::KeyListener(sf::Keyboard::Key _keyToListenFor)
	: keyToListenFor(_keyToListenFor),
	prevKeyState(false),
	toNotifyOnPress(),
	toNotifyOnRelease()
{
	// do nothing
}

KeyListener::NotifyListPos KeyListener::Register(KeyEvent eventToRegFor, Inputable* pInputable)
{
	NotifyListPos listPos;

	switch (eventToRegFor)
	{
	case KeyEvent::Press:
		listPos = toNotifyOnPress.insert(toNotifyOnPress.begin(), pInputable);
		break;
	case KeyEvent::Release:
		listPos = toNotifyOnRelease.insert(toNotifyOnRelease.begin(), pInputable);
		break;
	default:
		assert(false);
	}

	return listPos;
}

void KeyListener::Deregister(KeyEvent eventToDeregFor, NotifyListPos listPos)
{
	switch (eventToDeregFor)
	{
	case KeyEvent::Press:
		toNotifyOnPress.erase(listPos);
		break;
	case KeyEvent::Release:
		toNotifyOnRelease.erase(listPos);
		break;
	default:
		assert(false);
	}
}
