#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <list>

// forward declarations
class DrawObject;

class DrawManager
{
public:
	DrawManager();
	DrawManager(const DrawManager& dm);
	DrawManager& operator=(const DrawManager& dm);
	virtual ~DrawManager();

private:
	using DrawList = std::list<DrawObject*>;

public:
	using DrawListPos = DrawList::iterator;

	DrawListPos Register(DrawObject* pDraw);
	void Deregister(DrawListPos drawListPos);

	void DrawElements();
	
private:
	DrawList drawList;
};

#endif