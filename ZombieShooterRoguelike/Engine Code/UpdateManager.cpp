#include "UpdateManager.h"

#include "UpdateObject.h"

UpdateManager::UpdateManager()
	: updateList()
{
	// do nothing
}

UpdateManager::UpdateManager(const UpdateManager& um)
	: updateList(um.updateList)
{
	// do nothing
}

UpdateManager& UpdateManager::operator=(const UpdateManager& um)
{
	updateList = um.updateList;

	return *this;
}

UpdateManager::~UpdateManager()
{
	updateList.clear();
}

UpdateManager::UpdateListPos UpdateManager::Register(UpdateObject* pUp)
{
	return updateList.insert(updateList.begin(), pUp);
}

void UpdateManager::Deregister(UpdateListPos updateListPos)
{
	updateList.erase(updateListPos);
}

void UpdateManager::UpdateElements()
{
	for (UpdateListPos pos = updateList.begin(); pos != updateList.end(); pos++)
	{
		(*pos)->Update();
	}
}
