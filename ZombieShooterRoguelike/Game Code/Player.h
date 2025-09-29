#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics/Sprite.hpp"

#include "../Engine Code/UpdateObject.h"
#include "../Engine Code/DrawObject.h"

// forward declarations
class Weapon;

class Player : public UpdateObject, public DrawObject
{
public:
	Player();
	Player(const Player& p) = delete;
	Player& operator=(const Player& p) = delete;
	virtual ~Player();

	virtual void Update(float frameTime) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

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