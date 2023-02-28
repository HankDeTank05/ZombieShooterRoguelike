#ifndef DRAW_DEREGISTRATION_COMMAND_H
#define DRAW_DEREGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class Drawable;

class DrawDeregistrationCommand : public Command
{
public:
	DrawDeregistrationCommand() = delete;
	DrawDeregistrationCommand(Drawable* pDrawable);
	DrawDeregistrationCommand(const DrawDeregistrationCommand& ddc);
	DrawDeregistrationCommand& operator=(const DrawDeregistrationCommand& ddc);
	virtual ~DrawDeregistrationCommand();

	virtual void Execute() override;

private:
	Drawable* pDrawable;
};

#endif