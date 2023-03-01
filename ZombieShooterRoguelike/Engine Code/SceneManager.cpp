#include "SceneManager.h"

#include "Scene.h"

SceneManager* SceneManager::pInstance = nullptr;

SceneManager::SceneManager()
	: pCurrentScene(nullptr)
{
	// do nothing
}

SceneManager& SceneManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new SceneManager();
	}
	return *pInstance;
}

void SceneManager::SetStartScene(Scene* pScene)
{
	Instance().privSetStartScene(pScene);
}

Scene* SceneManager::GetCurrentScene()
{
	return Instance().privGetCurrentScene();
}

void SceneManager::UpdateCurrentScene()
{
	Instance().privUpdateCurrentScene();
}

void SceneManager::DrawCurrentScene()
{
	Instance().privDrawCurrentScene();
}

void SceneManager::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
