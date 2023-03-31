#ifndef TDRAWABLE_MANAGER_H
#define TDRAWABLE_MANAGER_H

#include <list>

// forward declarations
class TDrawable;

class TDrawableManager
{
public:
	TDrawableManager();
	TDrawableManager(const TDrawableManager& dm);
	TDrawableManager& operator=(const TDrawableManager& dm);
	virtual ~TDrawableManager();

private:
	using DrawList = std::list<TDrawable*>;

public:
	using DrawListPos = DrawList::iterator;

	DrawListPos Register(TDrawable* pDraw);
	void Deregister(DrawListPos drawListPos);

	void DrawElements();
	
private:
	DrawList drawList;
};

#endif