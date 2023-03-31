#ifndef DRAWABLE_MANAGER_H
#define DRAWABLE_MANAGER_H

#include <list>

// forward declarations
class Drawable;

class DrawableManager
{
public:
	DrawableManager();
	DrawableManager(const DrawableManager& dm);
	DrawableManager& operator=(const DrawableManager& dm);
	virtual ~DrawableManager();

private:
	using DrawList = std::list<Drawable*>;

public:
	using DrawListPos = DrawList::iterator;

	DrawListPos Register(Drawable* pDraw);
	void Deregister(DrawListPos drawListPos);

	void DrawElements();
	
private:
	DrawList drawList;
};

#endif