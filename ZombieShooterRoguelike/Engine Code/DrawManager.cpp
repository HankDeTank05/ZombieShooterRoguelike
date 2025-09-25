#include "DrawManager.h"

#include "DrawObject.h"
#include "EngineAttorney.h"

DrawManager::DrawManager()
	: drawList()
{
	// do nothing
}

DrawManager::DrawManager(const DrawManager& dm)
	: drawList(dm.drawList)
{
	// do nothing
}

DrawManager& DrawManager::operator=(const DrawManager& dm)
{
	drawList = dm.drawList;

	return *this;
}

DrawManager::~DrawManager()
{
	drawList.clear();
}

DrawManager::DrawListPos DrawManager::Register(DrawObject* pDraw)
{
	return drawList.insert(drawList.begin(), pDraw);
}

void DrawManager::Deregister(DrawListPos drawListPos)
{
	drawList.erase(drawListPos);
}

void DrawManager::DrawElements()
{
	for (DrawListPos pos = drawList.begin(); pos != drawList.end(); pos++)
	{
		(*pos)->draw(*EngineAttorney::Rendering::GetCurrentWindow(), sf::RenderStates::Default);
	}
}
