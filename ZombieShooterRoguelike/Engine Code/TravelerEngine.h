#ifndef TRAVELLER_ENGINE_H
#define TRAVELLER_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include <string>

class TravelerEngine	// set up as singleton
{
private:
	static TravelerEngine* pInstance;

	TravelerEngine();
	TravelerEngine(const TravelerEngine& te) = delete;
	TravelerEngine& operator=(const TravelerEngine& te) = delete;
	virtual ~TravelerEngine();

	static TravelerEngine& Instance();

private: // member variables
	sf::RenderWindow window;
	unsigned int screenWidth;
	unsigned int screenHeight;
	std::string windowName;
	sf::Color clearColor;

private: // core engine functions
	friend class EngineAttorney;
	void Initialize(); // for one-time non-graphic creation
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();

	void LoadAllResources(); // user-defined function
	void InitializeGame(); // user-defined function
	void EndGame(); // user-defined function

private: // private functions
	sf::RenderWindow* privGetCurrentWindow();

	unsigned int privGetScreenWidth();
	unsigned int privGetScreenHeight();
	void privSetClearColor(sf::Color color);
	void privSetWindowSize(unsigned int width, unsigned int height);

	void privRun();
	void privTerminate();

private: // engine/internal API functions (static)
	friend class EngineAttorney;
	static sf::RenderWindow* GetCurrentWindow();

public: // public API functions (static)
	static unsigned int GetScreenWidth();
	static unsigned int GetScreenHeight();
	static void SetClearColor(sf::Color color);
	static void SetWindowSize(unsigned int width, unsigned int height);

	static void Run();
	static void Terminate();
};

#endif