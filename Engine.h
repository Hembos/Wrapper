#pragma once
#include "Wrapper.h"
#include <string>
#include <map>

/// <summary>
/// Engine class stores the names of the commands and the wrappers for them. 
/// It allows you to create a new command based on a method of some class or function. 
/// It also allows you to call the appropriate command.
/// </summary>
class Engine
{
private:
	std::map<std::string, Wrapper*> commands;
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="wrapper">a wrapper for a function that stores information about it</param>
	/// <param name="commandName">new command name</param>
	void registerCommand(Wrapper* wrapper, std::string commandName);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="commandName"></param>
	/// <param name="arguments"></param>
	/// <returns></returns>
	int execute(std::string commandName, std::map<std::string, int> arguments);
};