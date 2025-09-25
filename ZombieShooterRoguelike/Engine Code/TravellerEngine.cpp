#include "TravelerEngine.h"

#include "Variables.h"

#include "TimeManagerAttorney.h"
#include "SpriteManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "SceneManager.h"
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
	// do nothing
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
	InitializeGame();
}

void TravelerEngine::LoadContent()
{
	LoadAllResources();
}

void TravelerEngine::Update()
{
	TimeManagerAttorney::Engine::ProcessTime();

	SceneManager::UpdateCurrentScene();
}

void TravelerEngine::Draw()
{
	SceneManager::DrawCurrentScene();
}

void TravelerEngine::UnloadContent()
{
	SpriteManagerAttorney::Termination::Terminate();
	TextureManagerAttorney::Termination::Terminate();
}

void TravelerEngine::privRun()
{
	TravelerEngine::Initialize();

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

void TravelerEngine::privTerminate()
{
	window.close();
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

void TravelerEngine::SetClearColor(sf::Color color)
{
	Instance().privSetClearColor(color);
}

void TravelerEngine::SetWindowSize(unsigned int width, unsigned int height)
{
	Instance().privSetWindowSize(width, height);
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
