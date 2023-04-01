#include "ScenePlayerTest.h"

#include "Player.h"

ScenePlayerTest::ScenePlayerTest()
	: pPlayer(nullptr)
{
	// do nothing
}

ScenePlayerTest::~ScenePlayerTest()
{
	if (pPlayer != nullptr)
	{
		delete pPlayer;
	}
}

void ScenePlayerTest::Initialize()
{
	pPlayer = new Player();
}

void ScenePlayerTest::SceneEnd()
{
	// CODE GOES HERE
}
