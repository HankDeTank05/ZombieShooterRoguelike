#include "TimeManagerAttorney.h"

#include "TimeManager.h"

void TimeManagerAttorney::Engine::ProcessTime()
{
	TimeManager::ProcessTime();
}

void TimeManagerAttorney::Termination::Terminate()
{
	TimeManager::Terminate();
}
