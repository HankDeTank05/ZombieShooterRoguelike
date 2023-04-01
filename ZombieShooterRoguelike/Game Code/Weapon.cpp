#include "Weapon.h"

#include <cassert>

Weapon::Weapon(int _magSize, int _magRounds, int _totalRounds)
	: magSize(_magSize),
	magRounds(_magRounds),
	totalRounds(_totalRounds)
{
	assert(magRounds <= magSize);
}
