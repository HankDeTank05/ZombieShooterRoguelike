#ifndef SPRITE_MANAGER_ATTORNEY_H
#define SPRITE_MANAGER_ATTORNEY_H

class SpriteManagerAttorney
{
public:
	class Termination
	{
	private:
		friend class TravelerEngine;
		static void Terminate();
	};
};

#endif