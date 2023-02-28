#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class TimeManager	// set up as singleton
{
private:
	static TimeManager* pInstance;

	TimeManager();
	TimeManager(const TimeManager& tm) = delete;
	TimeManager& operator=(const TimeManager& tm) = delete;
	virtual ~TimeManager();

	static TimeManager& Instance();

private: // member variables
	sf::Clock* pClock;
	sf::Time currentTime;
	sf::Time previousTime;
	sf::Time frameTime;

private: // private functions
	void privProcessTime();
	float privGetCurrentTime();
	float privGetFrameTime();

	void privTerminate();

private: // engine/internal API functions (static)
	friend class TimeManagerAttorney;
	static void ProcessTime();

public: // public API functions (static)
	static float GetCurrentTime();
	static float GetFrameTime();

	static void Terminate();
};

#endif