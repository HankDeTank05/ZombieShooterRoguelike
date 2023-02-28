#ifndef UPDATE_DEREGISTRATION_COMMAND_H
#define UPDATE_DEREGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class Updatable;

class UpdateDeregistrationCommand : public Command
{
public:
	UpdateDeregistrationCommand() = delete;
	UpdateDeregistrationCommand(Updatable* pUpdatable);
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand& udc);
	UpdateDeregistrationCommand& operator=(const UpdateDeregistrationCommand& udc);
	virtual ~UpdateDeregistrationCommand();

	virtual void Execute() override;

private:
	Updatable* pUpdatable;
};

#endif