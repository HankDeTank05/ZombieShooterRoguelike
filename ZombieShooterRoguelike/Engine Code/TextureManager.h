#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>

class TextureManager
{
private: // set up as a singleton
	static TextureManager* pInstance;

	TextureManager();
	TextureManager(const TextureManager& rTexMgr) = delete;
	TextureManager& operator=(const TextureManager& rTexMgr) = delete;
	virtual ~TextureManager();

	using TextureMap = std::map<std::string, sf::Texture>;

private: // member variables

private: // private functions
	void privTerminate();

public: // API functions (static)
	static void Terminate();
};

#endif