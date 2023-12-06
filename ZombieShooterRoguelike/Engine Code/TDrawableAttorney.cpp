#include "TDrawableAttorney.h"

#include "TDrawable.h"

void TDrawableAttorney::Registration::RegisterForDraw(TDrawable* pDrawable)
{
	pDrawable->RegisterForDraw();
}

void TDrawableAttorney::Registration::DeregisterForDraw(TDrawable* pDrawable)
{
	pDrawable->DeregisterForDraw();
}
