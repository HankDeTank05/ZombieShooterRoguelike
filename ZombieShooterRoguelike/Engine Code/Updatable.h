#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "RegistrationState.h"
#include "UpdatableManager.h"

// forward declarations
class UpdateRegistrationCommand;
class UpdateDeregistrationCommand;

class Updatable
{
public:
	Updatable();
	Updatable(const Updatable& u);
	Updatable& operator=(const Updatable& u);
	virtual ~Updatable();

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
	UpdatableManager::UpdateListPos deleteRef;
};

#endif