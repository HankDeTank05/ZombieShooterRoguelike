#ifndef UPDATE_MANAGER_H
#define UPDATE_MANAGER_H

#include <list>

// forward declarations
class UpdateObject;

class UpdateManager
{
public:
	UpdateManager();
	UpdateManager(const UpdateManager& um);
	UpdateManager& operator=(const UpdateManager& um);
	virtual ~UpdateManager();

private:
	using UpdateList = std::list<UpdateObject*>;

public:
	using UpdateListPos = UpdateList::iterator;

	UpdateListPos Register(UpdateObject* pUp);
	void Deregister(UpdateListPos updateListPos);

	void UpdateElements();

private:
	UpdateList updateList;
};

#endif