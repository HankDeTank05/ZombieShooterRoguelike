#ifndef DRAW_REGISTRATION_COMMAND_H
#define DRAW_REGISTRATION_COMMAND_H

#include "Command.h"

// forward declarations
class Drawable;

class DrawRegistrationCommand : public Command
{
public:
	DrawRegistrationCommand() = delete;
	DrawRegistrationCommand(Drawable* pDrawable);
	DrawRegistrationCommand(const DrawRegistrationCommand& drc);
	DrawRegistrationCommand& operator=(const DrawRegistrationCommand& drc);
	virtual ~DrawRegistrationCommand();

	virtual void Execute() override;

private:
	Drawable* pDrawable;
};

#endif