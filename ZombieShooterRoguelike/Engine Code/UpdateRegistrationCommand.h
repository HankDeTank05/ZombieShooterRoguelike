#ifndef UPDATE_REGISTRATION_COMMAND_H
#define UPDATE_REGISTRATION_COMMAND_H

#include "Command.h"

// forward declaration
class UpdateObject;

class UpdateRegistrationCommand : public Command
{
public:
	UpdateRegistrationCommand() = delete;
	UpdateRegistrationCommand(UpdateObject* pUpdatable);
	UpdateRegistrationCommand(const UpdateRegistrationCommand& urc);
	UpdateRegistrationCommand& operator=(const UpdateRegistrationCommand& urc);
	virtual ~UpdateRegistrationCommand();

	virtual void Execute() override;

private:
	UpdateObject* pUpdatable;
};

#endif