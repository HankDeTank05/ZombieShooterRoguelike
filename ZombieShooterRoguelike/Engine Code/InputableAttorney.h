#ifndef INPUTABLE_ATTORNEY_H
#define INPUTABLE_ATTORNEY_H

#include <SFML/Window/Keyboard.hpp>

#include "KeyEvent.h"

// forward declarations
class InputObject;

class InputableAttorney
{
public:

	class Registration
	{
	private:
		friend class InputRegistrationCommand;
		friend class InputDeregistrationCommand;
		static void RegisterForInputReading(InputObject* pInputable, sf::Keyboard::Key key, KeyEvent eventToRegFor);
		static void DeregisterForInputReading(InputObject* pInputable, sf::Keyboard::Key key, KeyEvent eventToDeregFor);
	};
};

#endif