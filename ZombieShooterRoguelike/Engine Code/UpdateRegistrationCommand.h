#ifndef UPDATE_REGISTRATION_COMMAND_H
#define UPDATE_REGISTRATION_COMMAND_H

#include "Command.h"

// forward declaration
class Updatable;

class UpdateRegistrationCommand : public Command
{
public:
	UpdateRegistrationCommand() = delete;
	UpdateRegistrationCommand(Updatable* pUpdatable);
	UpdateRegistrationCommand(const UpdateRegistrationCommand& urc);
	UpdateRegistrationCommand& operator=(const UpdateRegistrationCommand& urc);
	virtual ~UpdateRegistrationCommand();

	virtual void Execute() override;

private:
	Updatable* pUpdatable;
};

#endif