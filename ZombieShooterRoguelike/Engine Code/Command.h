#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
	Command() = default;
	Command(const Command& rCommand) = delete;
	Command& operator=(const Command& rCommand) = delete;
	virtual ~Command() = default;

	virtual void Execute() = 0;
};

#endif