#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "Weapon.h"

class Shotgun : public Weapon
{
public:
	Shotgun();
	Shotgun(const Shotgun& s) = delete;
	Shotgun& operator=(const Shotgun& s) = delete;
	virtual ~Shotgun();

	virtual void Fire(sf::Vector2f pos, sf::Vector2f dir) override;
	virtual void Reload() override;

	void IncreaseShotSpread();
	void IncreasePelletCount();
	void IncreaseEnemyPenetration();

private:
	float spreadWidthDeg;
	float spreadWidthDeltaDeg;
	float maxSpreadWidthDeg;
	int pelletsPerShot;
	int maxPelletsPerShot;
	int enemyPenetration;
	int maxEnemyPenetration;
};

#endif