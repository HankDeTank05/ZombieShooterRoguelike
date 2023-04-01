#include "TravellerEngine.h"

#include "Variables.h"

#include "TimeManagerAttorney.h"
#include "SpriteManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "SceneManager.h"
#include "Scene.h"

TravellerEngine* TravellerEngine::pInstance = nullptr;

TravellerEngine::TravellerEngine()
	: window(),
	screenWidth(Defaults::ScreenWidth),
	screenHeight(Defaults::ScreenHeight),
	windowName(Defaults::WindowName),
	clearColor(Defaults::ClearColor)
{
	// do nothing
}

TravellerEngine::~TravellerEngine()
{
	// do nothing
}

TravellerEngine& TravellerEngine::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new TravellerEngine();
	}
	return *pInstance;
}

void TravellerEngine::Initialize()
{
	InitializeGame();
}

void TravellerEngine::LoadContent()
{
	LoadAllResources();
}

void TravellerEngine::Update()
{
	TimeManagerAttorney::Engine::ProcessTime();

	SceneManager::UpdateCurrentScene();
}

void TravellerEngine::Draw()
{
	SceneManager::DrawCurrentScene();
}

void TravellerEngine::UnloadContent()
{
	SpriteManagerAttorney::Termination::Terminate();
	TextureManagerAttorney::Termination::Terminate();
}

void TravellerEngine::privRun()
{
	TravellerEngine::Initialize();

	TravellerEngine::LoadContent();

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

		TravellerEngine::Update();
		TravellerEngine::Draw();

		// end the current frame
		window.display();
	}

	TravellerEngine::UnloadContent();
}

void TravellerEngine::privTerminate()
{
	window.close();
}

sf::RenderWindow* TravellerEngine::GetCurrentWindow()
{
	return Instance().privGetCurrentWindow();
}

unsigned int TravellerEngine::GetScreenWidth()
{
	return Instance().privGetScreenWidth();
}

unsigned int TravellerEngine::GetScreenHeight()
{
	return Instance().privGetScreenHeight();
}

void TravellerEngine::SetClearColor(sf::Color color)
{
	Instance().privSetClearColor(color);
}

void TravellerEngine::SetWindowSize(unsigned int width, unsigned int height)
{
	Instance().privSetWindowSize(width, height);
}

void TravellerEngine::Run()
{
	Instance().privRun();
}

void TravellerEngine::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
