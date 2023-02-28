#ifndef UPDATABLE_MANAGER_H
#define UPDATABLE_MANAGER_H

#include <list>

// forward declarations
class Updatable;

class UpdatableManager
{
public:
	UpdatableManager();
	UpdatableManager(const UpdatableManager& rUpMgr);
	UpdatableManager& operator=(const UpdatableManager& rUpMgr);
	virtual ~UpdatableManager();

private:
	using UpdateList = std::list<Updatable*>;

public:
	using UpdateListPos = UpdateList::iterator;

	UpdateListPos Register(Updatable* pUp);
	void Deregister(UpdateListPos updateListPos);

	void UpdateElements();

private:
	UpdateList updateList;
};

#endif