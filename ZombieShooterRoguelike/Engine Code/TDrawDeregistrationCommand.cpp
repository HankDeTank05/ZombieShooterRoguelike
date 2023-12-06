#include "TDrawDeregistrationCommand.h"

#include "TDrawable.h"
#include "TDrawableAttorney.h"

TDrawDeregistrationCommand::TDrawDeregistrationCommand(TDrawable* _pDrawable)
	: pDrawable(_pDrawable)
{
	// do nothing
}

TDrawDeregistrationCommand::~TDrawDeregistrationCommand()
{
	// do nothing
}

void TDrawDeregistrationCommand::Execute()
{
	TDrawableAttorney::Registration::DeregisterForDraw(pDrawable);
}
