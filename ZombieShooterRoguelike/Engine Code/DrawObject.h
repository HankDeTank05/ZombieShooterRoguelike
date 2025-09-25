#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "RegistrationState.h"
#include "DrawManager.h"

// forward declarations
class TDrawRegistrationCommand;
class TDrawDeregistrationCommand;

class DrawObject : public sf::Drawable
{
public:
	DrawObject();
	DrawObject(const DrawObject& d) = delete;
	DrawObject& operator=(const DrawObject& d) = delete;
	virtual ~DrawObject();

	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) const = 0;
protected:

	virtual void EnqueueForDrawRegistration() final;
	virtual void EnqueueForDrawDeregistration() final;

private:
	friend class DrawObjectAttorney;

	void RegisterForDraw();
	void DeregisterForDraw();

private:
	RegistrationState regState;
	TDrawRegistrationCommand* pRegCmd;
	TDrawDeregistrationCommand* pDeregCmd;
	DrawManager::DrawListPos deleteRef;
};

#endif