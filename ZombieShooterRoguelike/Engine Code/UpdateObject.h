#ifndef UPDATE_OBJECT_H
#define UPDATE_OBJECT_H

#include "RegistrationState.h"
#include "UpdateManager.h"

// forward declarations
class UpdateRegistrationCommand;
class UpdateDeregistrationCommand;

class UpdateObject
{
public:
	UpdateObject();
	UpdateObject(const UpdateObject& u);
	UpdateObject& operator=(const UpdateObject& u);
	virtual ~UpdateObject();

	virtual void Update() = 0;
	
protected:
	virtual void EnqueueForUpdateRegistration() final;
	virtual void EnqueueForUpdateDeregistration() final;

public:
	void RegisterForUpdate();
	void DeregisterForUpdate();

private:
	RegistrationState regState;
	UpdateRegistrationCommand* pRegCmd;
	UpdateDeregistrationCommand* pDeregCmd;
	UpdateManager::UpdateListPos deleteRef;
};

#endif