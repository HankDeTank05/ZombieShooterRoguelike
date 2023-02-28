#include "RegistrationBroker.h"

#include "Command.h"

RegistrationBroker::RegistrationBroker()
	: cmdList()
{
	// do nothing
}

RegistrationBroker::RegistrationBroker(const RegistrationBroker& rb)
	: cmdList(rb.cmdList)
{
	// do nothing
}

RegistrationBroker& RegistrationBroker::operator=(const RegistrationBroker& rb)
{
	cmdList = rb.cmdList;

	return *this;
}

RegistrationBroker::~RegistrationBroker()
{
	cmdList.clear();
}

void RegistrationBroker::AddCommand(Command* pCmd)
{
	cmdList.push_back(pCmd);
}

void RegistrationBroker::ExecuteCommands()
{
	for (CommandList::iterator it = cmdList.begin(); it != cmdList.end(); it++)
	{
		(*it)->Execute();
	}
	cmdList.clear();
}
