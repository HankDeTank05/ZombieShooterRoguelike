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

KeyListener::~KeyListener()
{
	for (NotifyList::iterator it = toNotifyOnPress.begin(); it != toNotifyOnPress.end(); it++)
	{
		if ((*it) != nullptr)
		{
			delete (*it);
		}
	}

	for (NotifyList::iterator it = toNotifyOnRelease.begin(); it != toNotifyOnRelease.end(); it++)
	{
		if ((*it) != nullptr)
		{
			delete (*it);
		}
	}
}

KeyListener::NotifyListPos KeyListener::Register(KeyEvent eventToRegFor, InputObject* pInputable)
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
