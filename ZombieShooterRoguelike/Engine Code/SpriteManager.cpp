#include "SpriteManager.h"

#include "TextureManager.h"
#include <cassert>

SpriteManager* SpriteManager::pInstance = nullptr;

SpriteManager::SpriteManager()
	: spriteMap()
{
	// do nothing
}

SpriteManager::~SpriteManager()
{
	// do nothing
}

SpriteManager& SpriteManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new SpriteManager();
	}
	return *pInstance;
}

void SpriteManager::privLoadSprite(std::string texKeyName, std::string sprKeyName)
{
	assert(spriteMap.count(sprKeyName) == 0); // sprite key already exists in map!

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::GetTexture(texKeyName));

	spriteMap.insert(std::pair<std::string, sf::Sprite*>(sprKeyName, sprite));
}

void SpriteManager::privLoadSprite(std::string texKeyName, std::string sprKeyName, sf::IntRect subTex)
{
	assert(spriteMap.count(sprKeyName) == 0); // sprite key already exists in map!

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::GetTexture(texKeyName));
	sprite->setTextureRect(subTex);

	spriteMap.insert(std::pair<std::string, sf::Sprite*>(sprKeyName, sprite));
}

sf::Sprite* SpriteManager::privGetSprite(std::string keyName)
{
	assert(spriteMap.count(keyName) == 1); // key does not exist in map!
	return spriteMap.at(keyName);
}

void SpriteManager::privTerminate()
{
	for (SpriteMap::iterator it = spriteMap.begin(); it != spriteMap.end(); it++)
	{
		delete (*it).second;
	}
	spriteMap.clear();
}

void SpriteManager::LoadSprite(std::string texKeyName, std::string sprKeyName)
{
	Instance().privLoadSprite(texKeyName, sprKeyName);
}

void SpriteManager::LoadSprite(std::string texKeyName, std::string sprKeyName, sf::IntRect subTex)
{
	Instance().privLoadSprite(texKeyName, sprKeyName, subTex);
}

sf::Sprite* SpriteManager::GetSprite(std::string keyName)
{
	return Instance().privGetSprite(keyName);
}

void SpriteManager::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
