#pragma once
#include "Wrapper.h"
class Engine
{
public:
	void registerCommand(Wrapper* wrapper, std::string commandName)
	{
		if (commands.find(commandName) != commands.end())
			throw std::exception("Command already exists");

		commands.insert(std::make_pair(commandName, wrapper));
	}
	int execute(std::string commandName, std::map<std::string, int> args)
	{
		auto const& command = commands.find(commandName);

		if (command == commands.end())
			throw std::exception("Command doesn't exist");

		return command->second->funcExecute(args);
	}
private:
	std::map<std::string, Wrapper*> commands;
};