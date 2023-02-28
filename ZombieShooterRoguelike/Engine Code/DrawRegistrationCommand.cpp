#include "DrawRegistrationCommand.h"

DrawRegistrationCommand::DrawRegistrationCommand(Drawable* _pDrawable)
	: pDrawable(_pDrawable)
{
	// do nothing
}

DrawRegistrationCommand::DrawRegistrationCommand(const DrawRegistrationCommand& drc)
	: pDrawable(drc.pDrawable)
{
	// do nothing
}

DrawRegistrationCommand& DrawRegistrationCommand::operator=(const DrawRegistrationCommand& drc)
{
	pDrawable = drc.pDrawable;

	return *this;
}

DrawRegistrationCommand::~DrawRegistrationCommand()
{
	// do nothing
}
