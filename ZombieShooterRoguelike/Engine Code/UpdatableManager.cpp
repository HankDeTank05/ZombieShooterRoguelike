#include "UpdatableManager.h"

#include "Updatable.h"

UpdatableManager::UpdatableManager()
	: updateList()
{
	// do nothing
}

UpdatableManager::UpdatableManager(const UpdatableManager& um)
	: updateList(um.updateList)
{
	// do nothing
}

UpdatableManager& UpdatableManager::operator=(const UpdatableManager& um)
{
	updateList = um.updateList;

	return *this;
}

UpdatableManager::~UpdatableManager()
{
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
