#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

// forward declarations
class Scene;
class Command;

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

	void privInitStartScene();
	void privUpdateCurrentScene();
	void privDrawCurrentScene();

	void privTerminate();

public: // API functions (static)
	static void SetStartScene(Scene* pScene);
	static Scene* GetCurrentScene();

private: // internal-only api functions
	friend class SceneManagerAttorney;

	static void InitStartScene();
	static void UpdateCurrentScene();
	static void DrawCurrentScene();

	static void Terminate();
	
};

#endif