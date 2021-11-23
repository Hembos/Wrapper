#include "Engine.h"

void Engine::registerCommand(Wrapper* wrapper, std::string commandName)
{
	if (commands.find(commandName) != commands.end())
		throw std::exception("A command with the same name already exists");

	commands.insert(std::pair<std::string, Wrapper*>(commandName, wrapper));
}

int Engine::execute(std::string commandName, std::map<std::string, int> arguments)
{
	if (commands.find(commandName) == commands.end())
		throw std::exception("There is no such command");

	return commands.at(commandName)->call(arguments);
}