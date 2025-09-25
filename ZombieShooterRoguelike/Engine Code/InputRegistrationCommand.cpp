#include "InputRegistrationCommand.h"

#include "InputableAttorney.h"

InputRegistrationCommand::InputRegistrationCommand(InputObject* _pInputable, sf::Keyboard::Key _key, KeyEvent _eventToRegFor)
	: pInputable(_pInputable),
	key(_key),
	eventToRegFor(_eventToRegFor)
{
	// do nothing
}

InputRegistrationCommand::~InputRegistrationCommand()
{
	// do nothing
}

void InputRegistrationCommand::Execute()
{
	InputableAttorney::Registration::RegisterForInputReading(pInputable, key, eventToRegFor);
}
