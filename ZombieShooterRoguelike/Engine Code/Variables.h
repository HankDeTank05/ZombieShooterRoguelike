#ifndef VARIABLES_H
#define VAIRABLES_H

#include <string>
#include <SFML/Graphics/Color.hpp>

namespace Defaults
{
	// engine defaults
	const unsigned int ScreenWidth = 1280;
	const unsigned int ScreenHeight = 720;
	const std::string WindowName = "Traveller Engine";
	const sf::Color ClearColor = sf::Color::Black;

	// camera defaults
	const float CamTargetX = 0.0f;
	const float CamTargetY = 0.0f;
}

#endif