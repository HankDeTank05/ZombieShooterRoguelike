#ifndef WEAPON_H
#define WEAPON_H

#include "SFML/System/Vector2.hpp"

class Weapon
{
public:
	Weapon() = delete;
	Weapon(int magSize, int magRounds, int totalRounds);
	Weapon(const Weapon& w) = delete;
	Weapon& operator=(const Weapon& w) = delete;
	virtual ~Weapon() = default;

	virtual void Fire(sf::Vector2f pos, sf::Vector2f dir) = 0;
	virtual void Reload() = 0;

protected:
	int magSize;
	int magRounds;
	int totalRounds;
};

#endif