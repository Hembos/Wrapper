#pragma once
#include "Wrapper.h"
class Engine
{
public:
	/// <summary>
	/// Registers a new command with a wrapper and an appropriate name
	/// </summary>
	/// <param name="wrapper">Wrapper over function</param>
	/// <param name="commandName">The name of the command with which you can invoke this command</param>
	void registerCommand(Wrapper* wrapper, std::string commandName)
	{
		if (commands.find(commandName) != commands.end())
			throw std::exception("Command already exists");

		commands.insert(std::make_pair(commandName, wrapper));
	}

	/// <summary>
	/// Allows you to execute the corresponding command
	/// </summary>
	/// <param name="commandName">command name</param>
	/// <param name="args">arguments passed to the function</param>
	/// <returns>command result</returns>
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