#ifndef TDRAW_DEREGISTRATION_COMMAND_H
#define TDRAW_DEREGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class TDrawable;

class TDrawDeregistrationCommand : public Command
{
public:
	TDrawDeregistrationCommand() = delete;
	TDrawDeregistrationCommand(TDrawable* pDrawable);
	TDrawDeregistrationCommand(const TDrawDeregistrationCommand& ddc) = delete;
	TDrawDeregistrationCommand& operator=(const TDrawDeregistrationCommand& ddc) = delete;
	virtual ~TDrawDeregistrationCommand();

	virtual void Execute() override;

private:
	Drawable* pDrawable;
};

#endif