#include "TDrawableManager.h"

#include "TDrawable.h"
#include "EngineAttorney.h"

TDrawableManager::TDrawableManager()
	: drawList()
{
	// do nothing
}

TDrawableManager::TDrawableManager(const TDrawableManager& dm)
	: drawList(dm.drawList)
{
	// do nothing
}

TDrawableManager& TDrawableManager::operator=(const TDrawableManager& dm)
{
	drawList = dm.drawList;

	return *this;
}

TDrawableManager::~TDrawableManager()
{
	drawList.clear();
}

TDrawableManager::DrawListPos TDrawableManager::Register(TDrawable* pDraw)
{
	return drawList.insert(drawList.begin(), pDraw);
}

void TDrawableManager::Deregister(DrawListPos drawListPos)
{
	drawList.erase(drawListPos);
}

void TDrawableManager::DrawElements()
{
	for (DrawListPos pos = drawList.begin(); pos != drawList.end(); pos++)
	{
		(*pos)->draw(*EngineAttorney::Rendering::GetCurrentWindow(), sf::RenderStates::Default);
	}
}
