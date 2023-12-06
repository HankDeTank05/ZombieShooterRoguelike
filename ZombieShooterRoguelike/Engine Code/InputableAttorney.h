#ifndef INPUTABLE_ATTORNEY_H
#define INPUTABLE_ATTORNEY_H

#include <SFML/Window/Keyboard.hpp>

#include "KeyEvent.h"

// forward declarations
class Inputable;

class InputableAttorney
{
public:

	class Registration
	{
	private:
		friend class InputRegistrationCommand;
		friend class InputDeregistrationCommand;
		static void RegisterForInputReading(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToRegFor);
		static void DeregisterForInputReading(Inputable* pInputable, sf::Keyboard::Key key, KeyEvent eventToDeregFor);
	};
};

#endif