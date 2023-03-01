#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

// forward declarations
class Scene;

class SceneManager	// set up as singleton
{
private:
	static SceneManager* pInstance;

	SceneManager();
	SceneManager(const SceneManager& sm) = delete;
	SceneManager& operator=(const SceneManager& sm) = delete;
	virtual ~SceneManager();

	static SceneManager& Instance();

private: // member variables
	Scene* pCurrentScene;

private: // private functions
	void privSetStartScene(Scene* pScene);
	Scene* privGetCurrentScene();

	void privUpdateCurrentScene();
	void privDrawCurrentScene();

	void privTerminate();

public: // API functions (static)
	static void SetStartScene(Scene* pScene);
	static Scene* GetCurrentScene();

	static void UpdateCurrentScene();
	static void DrawCurrentScene();

	static void Terminate();
	
};

#endif