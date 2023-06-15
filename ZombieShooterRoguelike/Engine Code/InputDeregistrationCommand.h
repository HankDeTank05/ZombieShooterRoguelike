#ifndef INPUT_DEREGISTRATION_COMMAND_H
#define INPUT_DEREGISTRATION_COMMAND_H

#include <SFML/Window/Keyboard.hpp>

#include "Command.h"
#include "KeyEvent.h"

// forward declarations
class Inputable;

class InputDeregistrationCommand : public Command
{
public:
	InputDeregistrationCommand() = delete;
	InputDeregistrationCommand(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToDeregFor);
	InputDeregistrationCommand(const InputDeregistrationCommand& idc) = delete;
	InputDeregistrationCommand& operator=(const InputDeregistrationCommand& idc) = delete;
	virtual ~InputDeregistrationCommand();

	virtual void Execute() override;

private:
	Inputable* pInputable;
	sf::Keyboard::Key key;
	KeyEvent eventToDeregFor;
};

#endif