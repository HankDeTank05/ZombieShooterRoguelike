#include "../Engine Code/TravelerEngine.h"

#include "../Engine Code/TextureManager.h"
#include "../Engine Code/SpriteManager.h"
#include "../Engine Code/SceneManager.h"

#include "ScenePlayerTest.h"

void TravelerEngine::LoadAllResources()
{
	TextureManager::LoadTexure("tds.png", "spritesheet");

	SpriteManager::LoadSprite("spritesheet", "playerDir1", sf::IntRect( 8, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir2", sf::IntRect(16, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir3", sf::IntRect(24, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir4", sf::IntRect(32, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir5", sf::IntRect(40, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir6", sf::IntRect(48, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir7", sf::IntRect(56, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir8", sf::IntRect(64, 0, 8, 8));
	SpriteManager::LoadSprite("spritesheet", "playerDir9", sf::IntRect(72, 0, 8, 8));

	SpriteManager::LoadSprite("spritesheet", "pellet", sf::IntRect(0, 8, 8, 8));

	SceneManager::SetStartScene(new ScenePlayerTest());
	SceneManager::InitStartScene();
}