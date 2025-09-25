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
};

#endif