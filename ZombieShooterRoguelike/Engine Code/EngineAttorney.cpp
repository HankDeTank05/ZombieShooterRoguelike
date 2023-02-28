#include "EngineAttorney.h"

#include "TravellerEngine.h"

sf::RenderWindow* EngineAttorney::Rendering::GetCurrentWindow()
{
	return TravellerEngine::GetCurrentWindow();
}
