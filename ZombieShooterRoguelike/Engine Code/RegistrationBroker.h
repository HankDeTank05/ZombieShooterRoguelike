#ifndef REGISTRATION_BROKER_H
#define REGISTRATION_BROKER_H

class RegistrationBroker
{
public:
	RegistrationBroker();
	RegistrationBroker(const RegistrationBroker& rRegBroker);
	RegistrationBroker& operator=(const RegistrationBroker& rRegBroker);
	virtual ~RegistrationBroker();

	/// TODO: create the registration broker class

private:
	// member variables go here
};

#endif