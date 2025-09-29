#include "Pellet.h"

#include "../Engine Code/SpriteManager.h"

Pellet::Pellet(sf::Vector2f _pos, sf::Vector2f _dir)
	: pSprite(SpriteManager::GetSprite("pellet")),
	pos(_pos),
	dir(_dir)
{
	EnqueueForUpdateRegistration();
	EnqueueForDrawRegistration();
}

Pellet::Pellet(const Pellet& p)
	: pSprite(p.pSprite),
	pos(p.pos),
	dir(p.dir)
{
	// do nothing
}

Pellet::~Pellet()
{
	// do nothing
}

void Pellet::Update(float frameTime)
{
	pos += dir * frameTime; // TODO: multiply movement by speed
}

void Pellet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*pSprite);
}
