#include "InputableAttorney.h"

#include "Inputable.h"

void InputableAttorney::Registration::RegisterForInputReading(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToRegFor)
{
	pInputable->RegisterForInputReading(key, eventToRegFor);
}

void InputableAttorney::Registration::DeregisterForInputReading(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToDeregFor)
{
	pInputable->DeregisterForInputReading(key, eventToDeregFor);
}
