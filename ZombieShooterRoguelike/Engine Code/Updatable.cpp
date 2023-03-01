#include "Updatable.h"

#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"
#include <cassert>

Updatable::Updatable()
	: regState(RegistrationState::CurrentlyDeregistered),
	pRegCmd(new UpdateRegistrationCommand(this)),
	pDeregCmd(new UpdateDeregistrationCommand(this))
{
	// do nothing
}

Updatable::Updatable(const Updatable& u)
	: regState(u.regState),
	pRegCmd(new UpdateRegistrationCommand(*u.pRegCmd)),
	pDeregCmd(new UpdateDeregistrationCommand(*u.pDeregCmd))
{
	// do nothing
}

Updatable& Updatable::operator=(const Updatable& u)
{
	regState = u.regState;
	pRegCmd = new UpdateRegistrationCommand(*u.pRegCmd);
	pDeregCmd = new UpdateDeregistrationCommand(*u.pDeregCmd);

	return *this;
}

Updatable::~Updatable()
{
	delete pDeregCmd;
	delete pRegCmd;
}

void Updatable::EnqueueForUpdateRegistration()
{
	assert(regState == RegistrationState::CurrentlyDeregistered);


}
