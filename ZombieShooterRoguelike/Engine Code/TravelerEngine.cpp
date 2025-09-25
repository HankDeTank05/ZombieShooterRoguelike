#include "TravelerEngine.h"

#include "Variables.h"

#include "TimeManagerAttorney.h"
#include "SpriteManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "SceneManagerAttorney.h"
#include "Scene.h"

TravelerEngine* TravelerEngine::pInstance = nullptr;

TravelerEngine::TravelerEngine()
	: window(),
	screenWidth(Defaults::ScreenWidth),
	screenHeight(Defaults::ScreenHeight),
	windowName(Defaults::WindowName),
	clearColor(Defaults::ClearColor)
{
	// do nothing
}

TravelerEngine::~TravelerEngine()
{
	window.close();
}

TravelerEngine& TravelerEngine::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new TravelerEngine();
	}
	return *pInstance;
}

void TravelerEngine::Initialize()
{
	// TODO: initialize the engine here (one-time non-graphic creation)
}

void TravelerEngine::LoadContent()
{
	LoadAllResources();

	// TODO: initialize the starting scene here! (do it through attorney)
}

void TravelerEngine::Update()
{
	TimeManagerAttorney::Engine::ProcessTime();

	SceneManager::UpdateCurrentScene(); // TODO: make this go through attorney
}

void TravelerEngine::Draw()
{
	SceneManager::DrawCurrentScene(); // TODO: make this go through attorney
}

void TravelerEngine::UnloadContent()
{
	// terminate all engine systems
	SpriteManagerAttorney::Termination::Terminate();
	TextureManagerAttorney::Termination::Terminate();
	TimeManagerAttorney::Termination::Terminate();
	SceneManagerAttorney::Termination::Terminate();
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

std::string TravelerEngine::privGetWindowName()
{
	return windowName;
}

void TravelerEngine::privSetClearColor(sf::Color color)
{
	clearColor = color;
}

void TravelerEngine::privSetWindowSize(unsigned int width, unsigned int height)
{
	screenWidth = width;
	screenHeight = height;
	window.setSize(sf::Vector2u(screenWidth, screenHeight));
}

void TravelerEngine::privSetWindowName(std::string name)
{
	windowName = name;
	window.setTitle(windowName);
}

void TravelerEngine::privRun()
{
	TravelerEngine::Initialize();

	TravelerEngine::InitializeGame();

	TravelerEngine::LoadContent();

	// create the window
	window.create(sf::VideoMode(screenWidth, screenHeight), windowName);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// clear the window with black color
		window.clear(clearColor);

		TravelerEngine::Update();
		TravelerEngine::Draw();

		// end the current frame
		window.display();
	}

	TravelerEngine::UnloadContent();
}

sf::RenderWindow* TravelerEngine::GetCurrentWindow()
{
	return Instance().privGetCurrentWindow();
}

unsigned int TravelerEngine::GetScreenWidth()
{
	return Instance().privGetScreenWidth();
}

unsigned int TravelerEngine::GetScreenHeight()
{
	return Instance().privGetScreenHeight();
}

std::string TravelerEngine::GetWindowName()
{
	return Instance().privGetWindowName();
}

void TravelerEngine::SetClearColor(sf::Color color)
{
	Instance().privSetClearColor(color);
}

void TravelerEngine::SetWindowSize(unsigned int width, unsigned int height)
{
	Instance().privSetWindowSize(width, height);
}

void TravelerEngine::SetWindowName(std::string name)
{
	Instance().privSetWindowName(name);
}

void TravelerEngine::Run()
{
	Instance().privRun();
}

void TravelerEngine::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
