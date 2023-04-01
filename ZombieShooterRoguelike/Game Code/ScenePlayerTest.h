#ifndef SCENE_PLAYER_TEST_H
#define SCENE_PLAYER_TEST_H

// engine includes
#include "../Engine Code/Scene.h"

// game includes
#include "Player.h"

class ScenePlayerTest : public Scene
{
public:
	ScenePlayerTest();
	ScenePlayerTest(const ScenePlayerTest& spt) = delete;
	ScenePlayerTest& operator=(const ScenePlayerTest& spt) = delete;
	virtual ~ScenePlayerTest();

	virtual void Initialize() override;
	virtual void SceneEnd() override;

private:
	Player* pPlayer;
};

#endif