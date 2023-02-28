#ifndef TIME_MANAGER_ATTORNEY_H
#define TIME_MANAGER_ATTORNEY_H

class TimeManagerAttorney
{
public:
	class Engine
	{
		friend class TravellerEngine;
		static void ProcessTime();
	};
};

#endif