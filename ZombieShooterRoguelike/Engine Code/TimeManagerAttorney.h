#ifndef TIME_MANAGER_ATTORNEY_H
#define TIME_MANAGER_ATTORNEY_H

class TimeManagerAttorney
{
public:
	class Engine
	{
		friend class TravelerEngine;
		static void ProcessTime();
	};

	class Termination
	{
		friend class TravelerEngine;
		static void Terminate();
	};
};

#endif