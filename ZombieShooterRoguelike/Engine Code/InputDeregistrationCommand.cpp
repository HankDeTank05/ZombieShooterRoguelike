#include "InputDeregistrationCommand.h"

#include "InputableAttorney.h"

InputDeregistrationCommand::InputDeregistrationCommand(Inputable* _pInputable, sf::Keyboard::Key _key, KeyEvent _eventToDeregFor)
	: pInputable(_pInputable),
	key(_key),
	eventToDeregFor(_eventToDeregFor)
{
	// do nothing
}

InputDeregistrationCommand::~InputDeregistrationCommand()
{
	// do nothing
}

void InputDeregistrationCommand::Execute()
{
	InputableAttorney::Registration::DeregisterForInputReading(pInputable, key, eventToDeregFor);
}
