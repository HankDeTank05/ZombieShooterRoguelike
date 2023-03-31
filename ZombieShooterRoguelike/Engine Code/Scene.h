#ifndef SCENE_H
#define SCENE_H

#include "UpdatableManager.h"
#include "DrawableManager.h"

// forward declarations
class RegistrationBroker;
class CameraManager;
class Command;
class Updatable;
class Drawable;

class Scene
{
public:
	Scene();
	Scene(const Scene& s);
	Scene& operator=(const Scene& s);
	virtual ~Scene();

	virtual void Initialize() = 0;
	virtual void Update() final;
	virtual void Draw() final;
	virtual void SceneEnd() = 0;

public:
	void EnqueueCommand(Command* pCommand);

	UpdatableManager::UpdateListPos Register(Updatable* pUpdatable);
	void Deregister(UpdatableManager::UpdateListPos updateRef);
	DrawableManager::DrawListPos Register(Drawable* pDrawable);
	void Deregister(DrawableManager::DrawListPos drawRef);

private:
	RegistrationBroker* pRegBroker;

	UpdatableManager* pUpMgr;
	DrawableManager* pDrawMgr;
	CameraManager* pCamMgr;
};

#endif