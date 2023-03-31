#include "Drawable.h"

#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"

Drawable::Drawable()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new DrawRegistrationCommand(this)),
	pDeregCmd(new DrawDeregistrationCommand(this))
{
	// do nothing
}

Drawable::~Drawable()
{
	delete pDeregCmd;
	delete pRegCmd;
}