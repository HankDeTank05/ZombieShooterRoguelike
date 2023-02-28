#ifndef SCENE_H
#define SCENE_H

// forward declarations
class RegistrationBroker;
class UpdatableManager;
class DrawableManager;
class CameraManager;

class Scene
{
public:
	Scene();
	Scene(const Scene& rScene) = delete;
	Scene& operator=(const Scene& rScene) = delete;
	virtual ~Scene();

	virtual void Initialize() = 0;
	virtual void Update() final;
	virtual void Draw() final;
	virtual void SceneEnd() = 0;

	// virtual void SetCurrentCamera(Rendering* pCamera) final;
	// virtual Rendering* GetCurrentCamera() final;

private:
	RegistrationBroker* pRegBroker;

	UpdatableManager* pUpMgr;
	DrawableManager* pDrawMgr;
	CameraManager* pCamMgr;
};

#endif