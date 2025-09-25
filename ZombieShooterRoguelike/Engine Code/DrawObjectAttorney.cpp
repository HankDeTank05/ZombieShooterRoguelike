#include "DrawObjectAttorney.h"

#include "DrawObject.h"

void DrawObjectAttorney::Registration::RegisterForDraw(DrawObject* pDrawable)
{
	pDrawable->RegisterForDraw();
}

void DrawObjectAttorney::Registration::DeregisterForDraw(DrawObject* pDrawable)
{
	pDrawable->DeregisterForDraw();
}
