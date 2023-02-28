#include "UpdatableManager.h"

#include "Updatable.h"

UpdatableManager::UpdatableManager()
	: updateList()
{
	// do nothing
}

UpdatableManager::UpdatableManager(const UpdatableManager& rUpMgr)
	: updateList(rUpMgr.updateList)
{
	// do nothing
}

UpdatableManager& UpdatableManager::operator=(const UpdatableManager& rUpMgr)
{
	updateList = rUpMgr.updateList;

	return *this;
}

UpdatableManager::~UpdatableManager()
{
	for (UpdateListPos pos = updateList.begin(); pos != updateList.end(); pos++)
	{
		delete (*pos);
	}
	updateList.clear();
}

UpdatableManager::UpdateListPos UpdatableManager::Register(Updatable* pUp)
{
	return updateList.insert(updateList.begin(), pUp);
}

void UpdatableManager::Deregister(UpdateListPos updateListPos)
{
	updateList.erase(updateListPos);
}

void UpdatableManager::UpdateElements()
{
	for (UpdateListPos pos = updateList.begin(); pos != updateList.end(); pos++)
	{
		(*pos)->Update();
	}
}
