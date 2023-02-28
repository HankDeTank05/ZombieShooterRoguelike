#ifndef ENGINE_ATTORNEY_H
#define ENGINE_ATTORNEY_H

#include <SFML/Graphics.hpp>

class EngineAttorney
{
public:
	class Rendering
	{
	private:
		friend class DrawableManager;
		static sf::RenderWindow* GetCurrentWindow();
	};
};

#endif