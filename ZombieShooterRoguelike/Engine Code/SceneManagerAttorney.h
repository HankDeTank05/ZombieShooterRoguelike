#ifndef SCENE_MANAGER_ATTORNEY_H
#define SCENE_MANAGER_ATTORNEY_H

class SceneManagerAttorney
{
public:

	class EngineAccess
	{
		friend class TravelerEngine;
		static void InitStartScene();
		static void UpdateCurrentScene();
		static void DrawCurrentScene();
	};

	class Termination
	{
		friend class TravelerEngine;
		static void Terminate();
	};
};

#endif