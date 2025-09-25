#ifndef SCENE_MANAGER_ATTORNEY_H
#define SCENE_MANAGER_ATTORNEY_H

class SceneManagerAttorney
{
public:

	class Termination
	{
		friend class TravelerEngine;
		static void Terminate();
	};
};

#endif