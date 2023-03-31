#include "SceneManager.h"

#include "Scene.h"

SceneManager* SceneManager::pInstance = nullptr;

SceneManager::SceneManager()
	: pCurrentScene(nullptr)
{
	// do nothing
}

SceneManager::~SceneManager()
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

void SceneManager::privSetStartScene(Scene* pScene)
{
	pCurrentScene = pScene;
}

void SceneManager::privInitStartScene()
{
	pCurrentScene->Initialize();
}

Scene* SceneManager::privGetCurrentScene()
{
	return pCurrentScene;
}

void SceneManager::privUpdateCurrentScene()
{
	pCurrentScene->Update();
}

void SceneManager::privDrawCurrentScene()
{
	pCurrentScene->Draw();
}

void SceneManager::privTerminate()
{
	// do nothing
}

void SceneManager::SetStartScene(Scene* pScene)
{
	Instance().privSetStartScene(pScene);
}

void SceneManager::InitStartScene()
{
	Instance().privInitStartScene();
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
