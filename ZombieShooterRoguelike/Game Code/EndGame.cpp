#include "../Engine Code/TravellerEngine.h"

void TravellerEngine::EndGame()
{
	// GAME CODE GOES HERE TO END THE GAME
}

sf::RenderWindow* TravellerEngine::privGetCurrentWindow()
{
	return &window;
}

unsigned int TravellerEngine::privGetScreenWidth()
{
	return screenWidth;
}

unsigned int TravellerEngine::privGetScreenHeight()
{
	return screenHeight;
}

void TravellerEngine::privSetClearColor(sf::Color color)
{
	clearColor = color;
}

void TravellerEngine::privSetWindowSize(unsigned int width, unsigned int height)
{
	screenWidth = width;
	screenHeight = height;
	window.setSize(sf::Vector2u(width, height));
}
