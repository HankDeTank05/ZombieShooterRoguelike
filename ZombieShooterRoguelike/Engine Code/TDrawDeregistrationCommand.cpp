#include "TDrawDeregistrationCommand.h"

#include "DrawObject.h"
#include "DrawObjectAttorney.h"

TDrawDeregistrationCommand::TDrawDeregistrationCommand(DrawObject* _pDrawable)
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
	DrawObjectAttorney::Registration::DeregisterForDraw(pDrawable);
}
