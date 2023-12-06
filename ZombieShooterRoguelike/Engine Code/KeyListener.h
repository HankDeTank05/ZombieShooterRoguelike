#ifndef KEY_LISTENER_H
#define KEY_LISTENER_H

#include <list>

#include <SFML/Window/Keyboard.hpp>

#include "KeyEvent.h"

// forward declarations
class Inputable;

class KeyListener
{
public:
	KeyListener() = delete;
	KeyListener(sf::Keyboard::Key keyToListenFor);
	KeyListener(const KeyListener& kl) = delete;
	KeyListener& operator=(const KeyListener& kl) = delete;
	virtual ~KeyListener();

private:
	using NotifyList = std::list<Inputable*>;

public:
	using NotifyListPos = NotifyList::iterator;

public:
	NotifyListPos Register(KeyEvent eventToRegFor, Inputable* pInputable);
	void Deregister(KeyEvent eventToDeregFor, NotifyListPos listPos);

private:
	sf::Keyboard::Key keyToListenFor;
	bool prevKeyState;
	NotifyList toNotifyOnPress;
	NotifyList toNotifyOnRelease;
};

#endif