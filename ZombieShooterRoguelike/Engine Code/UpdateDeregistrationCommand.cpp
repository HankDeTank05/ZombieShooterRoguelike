#include "UpdateDeregistrationCommand.h"

#include "Updatable.h"

UpdateDeregistrationCommand::UpdateDeregistrationCommand(Updatable* _pUpdatable)
	: pUpdatable(_pUpdatable)
{
	// do nothing
}

UpdateDeregistrationCommand::UpdateDeregistrationCommand(const UpdateDeregistrationCommand& udc)
	: pUpdatable(udc.pUpdatable)
{
}

UpdateDeregistrationCommand& UpdateDeregistrationCommand::operator=(const UpdateDeregistrationCommand& udc)
{
	pUpdatable = udc.pUpdatable;

	return *this;
}

UpdateDeregistrationCommand::~UpdateDeregistrationCommand()
{
	// do nothing
}

void UpdateDeregistrationCommand::Execute()
{
	pUpdatable->DeregisterForUpdate();
}
