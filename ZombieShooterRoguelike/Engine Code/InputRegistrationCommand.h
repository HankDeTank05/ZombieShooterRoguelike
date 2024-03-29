#ifndef INPUT_REGISTRATION_COMMAND_H
#define INPUT_REGISTRATION_COMMAND_H

#include <SFML/Window/Keyboard.hpp>

#include "Command.h"
#include "KeyEvent.h"

// forward declarations
class Inputable;

class InputRegistrationCommand : public Command
{
public:
	InputRegistrationCommand() = delete;
	InputRegistrationCommand(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToRegFor);
	InputRegistrationCommand(const InputRegistrationCommand& irc) = delete;
	InputRegistrationCommand& operator=(const InputRegistrationCommand& irc) = delete;
	virtual ~InputRegistrationCommand();

	virtual void Execute() override;
	
private:
	Inputable* pInputable;
	sf::Keyboard::Key key;
	KeyEvent eventToRegFor;
};

#endif