#ifndef SCENE_PLAYER_TEST_H
#define SCENE_PLAYER_TEST_H

#include "../Engine Code/Scene.h"

class ScenePlayerTest : public Scene
{
public:
	ScenePlayerTest();
	ScenePlayerTest(const ScenePlayerTest& spt) = delete;
	ScenePlayerTest& operator=(const ScenePlayerTest& spt) = delete;
	virtual ~ScenePlayerTest();
};

#endif