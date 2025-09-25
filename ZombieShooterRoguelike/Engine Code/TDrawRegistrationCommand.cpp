#include "TDrawRegistrationCommand.h"

#include "DrawObject.h"
#include "DrawObjectAttorney.h"

TDrawRegistrationCommand::TDrawRegistrationCommand(DrawObject* _pDrawable)
	: pDrawable(_pDrawable)
{
	// do nothing
}

TDrawRegistrationCommand::TDrawRegistrationCommand(const TDrawRegistrationCommand& drc)
	: pDrawable(drc.pDrawable)
{
	// do nothing
}

TDrawRegistrationCommand& TDrawRegistrationCommand::operator=(const TDrawRegistrationCommand& drc)
{
	pDrawable = drc.pDrawable;

	return *this;
}

TDrawRegistrationCommand::~TDrawRegistrationCommand()
{
	// do nothing
}

void TDrawRegistrationCommand::Execute()
{

	DrawObjectAttorney::Registration::RegisterForDraw(pDrawable);
}
