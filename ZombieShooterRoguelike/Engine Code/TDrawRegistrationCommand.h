#ifndef TDRAW_REGISTRATION_COMMAND_H
#define TDRAW_REGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class TDrawable;

class TDrawRegistrationCommand : public Command
{
public:
	TDrawRegistrationCommand() = delete;
	TDrawRegistrationCommand(TDrawable* pDrawable);
	TDrawRegistrationCommand(const TDrawRegistrationCommand& drc);
	TDrawRegistrationCommand& operator=(const TDrawRegistrationCommand& drc);
	virtual ~TDrawRegistrationCommand();

	virtual void Execute() override;

private:
	TDrawable* pDrawable;
};

#endif