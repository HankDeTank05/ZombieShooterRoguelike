#include "EngineAttorney.h"

#include "TravelerEngine.h"

sf::RenderWindow* EngineAttorney::Rendering::GetCurrentWindow()
{
	return TravelerEngine::GetCurrentWindow();
}
