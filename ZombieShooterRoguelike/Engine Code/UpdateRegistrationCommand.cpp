#include "UpdateRegistrationCommand.h"

UpdateRegistrationCommand::UpdateRegistrationCommand(Updatable* _pUpdatable)
	: pUpdatable(_pUpdatable)
{
	// do nothing
}

UpdateRegistrationCommand::UpdateRegistrationCommand(const UpdateRegistrationCommand& urc)
	: pUpdatable(urc.pUpdatable)
{
}

UpdateRegistrationCommand& UpdateRegistrationCommand::operator=(const UpdateRegistrationCommand& urc)
{
	pUpdatable = urc.pUpdatable;

	return *this;
}

UpdateRegistrationCommand::~UpdateRegistrationCommand()
{
	// do nothing
}
