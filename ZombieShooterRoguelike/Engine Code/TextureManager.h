#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <string>

class TextureManager	// set up as a singleton
{
private:
	static TextureManager* pInstance;

	TextureManager();
	TextureManager(const TextureManager& rTexMgr) = delete;
	TextureManager& operator=(const TextureManager& rTexMgr) = delete;
	virtual ~TextureManager();

	static TextureManager& Instance();

	using TextureMap = std::map<std::string, sf::Texture*>;

private: // member variables
	TextureMap textureMap;

private: // private functions
	void privLoadTexture(std::string filePath, std::string keyName, bool renderSmooth, bool renderRepeated);
	sf::Texture* privGetTexture(std::string keyName);

	void privTerminate();

public: // API functions (static)
	static void LoadTexure(std::string filePath, std::string keyName, bool renderSmooth = false, bool renderRepeated = false);
	static sf::Texture* GetTexture(std::string keyName);

	static void Terminate();
};

#endif