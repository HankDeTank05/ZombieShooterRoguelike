#ifndef TDRAW_REGISTRATION_COMMAND_H
#define TDRAW_REGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class DrawObject;

class TDrawRegistrationCommand : public Command
{
public:
	TDrawRegistrationCommand() = delete;
	TDrawRegistrationCommand(DrawObject* pDrawable);
	TDrawRegistrationCommand(const TDrawRegistrationCommand& drc);
	TDrawRegistrationCommand& operator=(const TDrawRegistrationCommand& drc);
	virtual ~TDrawRegistrationCommand();

	virtual void Execute() override;

private:
	DrawObject* pDrawable;
};

#endif