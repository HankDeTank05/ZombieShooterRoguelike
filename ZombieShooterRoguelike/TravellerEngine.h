#ifndef TRAVELLER_ENGINE_H
#define TRAVELLER_ENGINE_H

#include "olcPixelGameEngine.h"

class TravellerEngine : public olc::PixelGameEngine
{
public:
	TravellerEngine();
	TravellerEngine(const TravellerEngine& rTraveller) = delete;
	TravellerEngine& operator=(const TravellerEngine& rTraveller) = delete;
	virtual ~TravellerEngine();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	// member variables go here
};

#endif