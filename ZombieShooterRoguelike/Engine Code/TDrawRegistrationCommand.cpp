#include "TDrawRegistrationCommand.h"

#include "TDrawable.h"
#include "TDrawableAttorney.h"

TDrawRegistrationCommand::TDrawRegistrationCommand(TDrawable* _pDrawable)
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

	TDrawableAttorney::Registration::RegisterForDraw(pDrawable);
}
