#ifndef PELLET_H
#define PELLET_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include "../Engine Code/Updatable.h"
#include "../Engine Code/TDrawable.h"

class Pellet : public Updatable, public TDrawable
{
public:
	Pellet() = delete;
	Pellet(sf::Vector2f pos, sf::Vector2f dir);
	Pellet(const Pellet& p);
	Pellet& operator=(const Pellet& p) = delete;
	virtual ~Pellet();

	virtual void Update() override;
	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) const override;

private:
	sf::Sprite* pSprite;
	sf::Vector2f pos;
	sf::Vector2f dir;
};

#endif