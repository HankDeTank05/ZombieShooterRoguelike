#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Drawable : public sf::Drawable
{
public:
	Drawable();
	Drawable(const Drawable& d);
	Drawable& operator=(const Drawable& d);
	virtual ~Drawable();

	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) = 0;
};

#endif