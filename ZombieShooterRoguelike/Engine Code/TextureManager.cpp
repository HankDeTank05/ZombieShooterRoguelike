#include "TextureManager.h"

#include <cassert>

TextureManager* TextureManager::pInstance = nullptr;

TextureManager::TextureManager()
	: textureMap()
{
	// do nothing
}

TextureManager::~TextureManager()
{
	// do nothing
}

TextureManager& TextureManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new TextureManager();
	}
	return *pInstance;
}

void TextureManager::privLoadTexture(std::string filePath, std::string keyName, bool renderSmooth, bool renderRepeated)
{
	assert(textureMap.count(keyName) == 0); // key already exists in the map!

	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile(filePath) == false)
	{
		assert(false); // file could not be loaded!
	}

	texture->setSmooth(renderSmooth);
	texture->setRepeated(renderRepeated);

	textureMap.insert(std::pair<std::string, sf::Texture*>(keyName, texture));
}

sf::Texture* TextureManager::privGetTexture(std::string keyName)
{
	assert(textureMap.count(keyName) == 1); // key does not exist in map!
	return textureMap.at(keyName);
}

void TextureManager::privTerminate()
{
	for (TextureMap::iterator it = textureMap.begin(); it != textureMap.end(); it++)
	{
		delete (*it).second;
	}
	textureMap.clear();
}

void TextureManager::LoadTexure(std::string filePath, std::string keyName, bool renderSmooth, bool renderRepeated)
{
	Instance().privLoadTexture(filePath, keyName, renderSmooth, renderRepeated);
}

sf::Texture* TextureManager::GetTexture(std::string keyName)
{
	return Instance().privGetTexture(keyName);
}

void TextureManager::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
