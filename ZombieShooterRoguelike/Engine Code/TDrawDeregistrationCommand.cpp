#include "TDrawDeregistrationCommand.h"

#include "TDrawable.h"

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
	pDrawable->DeregisterForDraw();
}
