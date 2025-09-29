#ifndef CROSSHAIR_H
#define CROSSHAIR_H

// engine includes
#include "../Engine Code/UpdateObject.h"
#include "../Engine Code/DrawObject.h"

class Crosshair : public UpdateObject, public DrawObject
{
public:
	Crosshair() = default;
	Crosshair(const Crosshair& c) = delete;
	Crosshair& operator=(const Crosshair& c) = delete;
	virtual ~Crosshair() = default;

public:
	virtual void Update(float frameTime) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif