#ifndef SCENE_H
#define SCENE_H

#include "UpdateManager.h"
#include "DrawManager.h"
#include "KeyListener.h"
#include "InputManager.h"

// forward declarations
class RegistrationBroker;
class CameraManager;
class Command;
class UpdateObject;
class DrawObject;

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

	UpdateManager::UpdateListPos Register(UpdateObject* pUpdatable);
	void Deregister(UpdateManager::UpdateListPos updateRef);

	DrawManager::DrawListPos Register(DrawObject* pDrawable);
	void Deregister(DrawManager::DrawListPos drawRef);

	KeyListener::NotifyListPos Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, InputObject* pInputable);
	void Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos inputRef);

private:
	RegistrationBroker* pRegBroker;

	UpdateManager* pUpMgr;
	DrawManager* pDrawMgr;
	InputManager* pInMgr;

	CameraManager* pCamMgr;
};

#endif