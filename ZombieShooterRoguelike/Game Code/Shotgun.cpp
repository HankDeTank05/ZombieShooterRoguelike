#include "Shotgun.h"

#include "Pellet.h"

Shotgun::Shotgun()
	: Weapon(2, 2, 10),
	spreadWidthDeg(5.625f),
	spreadWidthDeltaDeg(5.625f),
	maxSpreadWidthDeg(90.0f),
	pelletsPerShot(2),
	maxPelletsPerShot(10),
	enemyPenetration(0),
	maxEnemyPenetration(10)
{
	// do nothing
}

Shotgun::~Shotgun()
{
	// do nothing
}

void Shotgun::Fire(sf::Vector2f pos, sf::Vector2f dir)
{
	float halfSpreadDeg = spreadWidthDeg / 2.0f;
	float spreadSliceDeg = spreadWidthDeg / static_cast<float>(pelletsPerShot - 1);

	for (int b = 0; b < pelletsPerShot; b++)
	{
		float dirDeg = atan2f(dir.y, dir.x) + halfSpreadDeg - (b * spreadSliceDeg);
		float dirRad = dirDeg * (3.14159f / 180.0f);
		sf::Vector2f pelletDir = sf::Vector2f(cosf(dirRad), sinf(dirRad));
		Pellet p = Pellet(pos, pelletDir);
	}
}

void Shotgun::Reload()
{
	totalRounds -= (magSize - magRounds);
}
