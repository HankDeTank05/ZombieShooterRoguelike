#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>

class SpriteManager		// set up as singleton
{
private:
	static SpriteManager* pInstance;

	SpriteManager();
	SpriteManager(const SpriteManager& rSprMgr) = delete;
	SpriteManager& operator=(const SpriteManager& rSprMgr) = delete;
	virtual ~SpriteManager();

	static SpriteManager& Instance();

	using SpriteMap = std::map<std::string, sf::Sprite*>;

private: // member variables
	SpriteMap spriteMap;

private: // private functions
	void privLoadSprite(std::string texKeyName, std::string sprKeyName);
	void privLoadSprite(std::string texKeyName, std::string sprKeyName, sf::IntRect subTex);
	sf::Sprite* privGetSprite(std::string keyName);

	void privTerminate();

public: // public API functions (static)
	static void LoadSprite(std::string texKeyName, std::string sprKeyName);
	static void LoadSprite(std::string texKeyName, std::string sprKeyName, sf::IntRect subTex);
	static sf::Sprite* GetSprite(std::string keyName);

private: // engine/internal API functions (static)
	friend class SpriteManagerAttorney;
	static void Terminate();
};

#endif