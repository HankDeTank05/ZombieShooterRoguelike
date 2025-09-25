#include "InputableAttorney.h"

#include "InputObject.h"

void InputableAttorney::Registration::RegisterForInputReading(InputObject* pInputable, sf::Keyboard::Key key, KeyEvent eventToRegFor)
{
	pInputable->RegisterForInputReading(key, eventToRegFor);
}

void InputableAttorney::Registration::DeregisterForInputReading(InputObject* pInputable, sf::Keyboard::Key key, KeyEvent eventToDeregFor)
{
	pInputable->DeregisterForInputReading(key, eventToDeregFor);
}
