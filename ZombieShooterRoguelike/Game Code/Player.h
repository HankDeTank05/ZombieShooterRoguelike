#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics/Sprite.hpp"

#include "../Engine Code/Updatable.h"
#include "../Engine Code/TDrawable.h"

// forward declarations
class Weapon;

class Player : public Updatable, public TDrawable
{
public:
	Player();
	Player(const Player& p) = delete;
	Player& operator=(const Player& p) = delete;
	virtual ~Player();

	virtual void Update() override;
	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) const override;

private:
	void MoveNorth();
	void MoveEast();
	void MoveSouth();
	void MoveWest();

	void Fire();
	void Reload();

private:
	sf::Sprite* spriteCurrent;
	sf::Vector2f pos;
	sf::Vector2f dir;
	sf::Vector2f posDelta;
	float speed;
	Weapon* pWeapon;

};

#endif