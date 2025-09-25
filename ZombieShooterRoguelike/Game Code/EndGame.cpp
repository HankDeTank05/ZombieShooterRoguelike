#include "../Engine Code/TravelerEngine.h"

void TravelerEngine::EndGame()
{
	// GAME CODE GOES HERE TO END THE GAME
}

sf::RenderWindow* TravelerEngine::privGetCurrentWindow()
{
	return &window;
}

unsigned int TravelerEngine::privGetScreenWidth()
{
	return screenWidth;
}

unsigned int TravelerEngine::privGetScreenHeight()
{
	return screenHeight;
}

void TravelerEngine::privSetClearColor(sf::Color color)
{
	clearColor = color;
}

void TravelerEngine::privSetWindowSize(unsigned int width, unsigned int height)
{
	screenWidth = width;
	screenHeight = height;
	window.setSize(sf::Vector2u(width, height));
}
