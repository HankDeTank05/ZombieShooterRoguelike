#ifndef REGISTRATION_BROKER_H
#define REGISTRATION_BROKER_H

#include <list>

// forward declarations
class Command;

class RegistrationBroker
{
public:
	RegistrationBroker();
	RegistrationBroker(const RegistrationBroker& rb);
	RegistrationBroker& operator=(const RegistrationBroker& rb);
	virtual ~RegistrationBroker();

	void AddCommand(Command* pCmd);
	void ExecuteCommands();

private:
	using CommandList = std::list<Command*>;
	CommandList cmdList;
};

#endif