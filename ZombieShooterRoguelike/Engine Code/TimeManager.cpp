#include "TimeManager.h"

TimeManager* TimeManager::pInstance = nullptr;

TimeManager::TimeManager()
	: pClock(new sf::Clock()),
	currentTime(pClock->getElapsedTime()),
	previousTime(sf::seconds(0.0f)),
	frameTime(sf::seconds(0.0f))
{
	// do nothing
}

TimeManager::~TimeManager()
{
	delete pClock;
}

TimeManager& TimeManager::Instance()
{
	if (pInstance == nullptr)
	{
		pInstance = new TimeManager();
	}
	return *pInstance;
}

void TimeManager::privProcessTime()
{
	previousTime = currentTime;

	currentTime = pClock->getElapsedTime();

	frameTime = currentTime - previousTime;
}

float TimeManager::privGetCurrentTime()
{
	return currentTime.asSeconds();
}

float TimeManager::privGetFrameTime()
{
	return frameTime.asSeconds();
}

void TimeManager::privTerminate()
{
	// do nothing
}

void TimeManager::ProcessTime()
{
	Instance().privProcessTime();
}

float TimeManager::GetCurrentTime()
{
	return Instance().privGetCurrentTime();
}

float TimeManager::GetFrameTime()
{
	return Instance().privGetFrameTime();
}

void TimeManager::Terminate()
{
	Instance().privTerminate();

	delete pInstance;
	pInstance = nullptr;
}
