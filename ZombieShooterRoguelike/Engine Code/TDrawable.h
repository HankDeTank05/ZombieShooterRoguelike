#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "RegistrationState.h"

// forward declarations
class DrawRegistrationCommand;
class DrawDeregistrationCommand;

class TDrawable : public sf::Drawable
{
public:
	TDrawable();
	TDrawable(const TDrawable& d) = delete;
	TDrawable& operator=(const TDrawable& d) = delete;
	virtual ~TDrawable();

	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) = 0;

private:
	RegistrationState regState;
	DrawRegistrationCommand* pRegCmd;
	DrawDeregistrationCommand* pDeregCmd;
};

#endif