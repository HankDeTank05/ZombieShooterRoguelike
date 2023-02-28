#ifndef REGISTRATION_BROKER_H
#define REGISTRATION_BROKER_H

#include <list>

// forward declarations
class Command;

class RegistrationBroker
{
public:
	RegistrationBroker();
	RegistrationBroker(const RegistrationBroker& rRegBroker) = default;
	RegistrationBroker& operator=(const RegistrationBroker& rRegBroker) = default;
	virtual ~RegistrationBroker();

	void AddCommand(Command* pCmd);
	void ExecuteCommands();

private:
	using CommandList = std::list<Command*>;
	CommandList cmdList;
};

#endif