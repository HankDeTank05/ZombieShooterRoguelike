#ifndef TDRAWABLE_H
#define TDRAWABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "RegistrationState.h"
#include "TDrawableManager.h"

// forward declarations
class TDrawRegistrationCommand;
class TDrawDeregistrationCommand;

class TDrawable : public sf::Drawable
{
public:
	TDrawable();
	TDrawable(const TDrawable& d) = delete;
	TDrawable& operator=(const TDrawable& d) = delete;
	virtual ~TDrawable();

	virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) const = 0;
protected:

	virtual void EnqueueForDrawRegistration() final;
	virtual void EnqueueForDrawDeregistration() final;

public:
	void RegisterForDraw();
	void DeregisterForDraw();

private:
	RegistrationState regState;
	TDrawRegistrationCommand* pRegCmd;
	TDrawDeregistrationCommand* pDeregCmd;
	TDrawableManager::DrawListPos deleteRef;
};

#endif