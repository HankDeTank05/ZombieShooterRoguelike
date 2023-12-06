#ifndef SCENE_H
#define SCENE_H

#include "UpdatableManager.h"
#include "TDrawableManager.h"
#include "KeyListener.h"
#include "InputableManager.h"

// forward declarations
class RegistrationBroker;
class CameraManager;
class Command;
class Updatable;
class TDrawable;

class Scene
{
public:
	Scene();
	Scene(const Scene& s) = delete;
	Scene& operator=(const Scene& s) = delete;
	virtual ~Scene();

	virtual void Initialize() = 0;
	virtual void Update() final;
	virtual void Draw() final;
	virtual void SceneEnd() = 0;

public:
	void EnqueueCommand(Command* pCommand);

	UpdatableManager::UpdateListPos Register(Updatable* pUpdatable);
	void Deregister(UpdatableManager::UpdateListPos updateRef);

	TDrawableManager::DrawListPos Register(TDrawable* pDrawable);
	void Deregister(TDrawableManager::DrawListPos drawRef);

	KeyListener::NotifyListPos Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, Inputable* pInputable);
	void Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos inputRef);

private:
	RegistrationBroker* pRegBroker;

	UpdatableManager* pUpMgr;
	TDrawableManager* pDrawMgr;
	InputableManager* pInMgr;

	CameraManager* pCamMgr;
};

#endif