#ifndef TDRAW_DEREGISTRATION_COMMAND_H
#define TDRAW_DEREGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class DrawObject;

class TDrawDeregistrationCommand : public Command
{
public:
	TDrawDeregistrationCommand() = delete;
	TDrawDeregistrationCommand(DrawObject* pDrawable);
	TDrawDeregistrationCommand(const TDrawDeregistrationCommand& ddc) = delete;
	TDrawDeregistrationCommand& operator=(const TDrawDeregistrationCommand& ddc) = delete;
	virtual ~TDrawDeregistrationCommand();

	virtual void Execute() override;

private:
	DrawObject* pDrawable;
};

#endif