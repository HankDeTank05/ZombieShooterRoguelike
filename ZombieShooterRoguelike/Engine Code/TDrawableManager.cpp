#include "DrawableManager.h"

#include "Drawable.h"
#include "EngineAttorney.h"

DrawableManager::DrawableManager()
	: drawList()
{
	// do nothing
}

DrawableManager::DrawableManager(const DrawableManager& dm)
	: drawList(dm.drawList)
{
	// do nothing
}

DrawableManager& DrawableManager::operator=(const DrawableManager& dm)
{
	drawList = dm.drawList;

	return *this;
}

DrawableManager::~DrawableManager()
{
	drawList.clear();
}

DrawableManager::DrawListPos DrawableManager::Register(Drawable* pDraw)
{
	return drawList.insert(drawList.begin(), pDraw);
}

void DrawableManager::Deregister(DrawListPos drawListPos)
{
	drawList.erase(drawListPos);
}

void DrawableManager::DrawElements()
{
	for (DrawListPos pos = drawList.begin(); pos != drawList.end(); pos++)
	{
		(*pos)->draw(*EngineAttorney::Rendering::GetCurrentWindow(), sf::RenderStates::Default);
	}
}
