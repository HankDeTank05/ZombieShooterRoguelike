#include "SceneManagerAttorney.h"

// engine includes
#include "SceneManager.h"

void SceneManagerAttorney::EngineAccess::InitStartScene()
{
	SceneManager::InitStartScene();
}

void SceneManagerAttorney::EngineAccess::UpdateCurrentScene()
{
	SceneManager::UpdateCurrentScene();
}

void SceneManagerAttorney::EngineAccess::DrawCurrentScene()
{
	SceneManager::DrawCurrentScene();
}

void SceneManagerAttorney::Termination::Terminate()
{
	SceneManager::Terminate();
}