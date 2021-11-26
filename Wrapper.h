#pragma once
#include <functional>
#include <vector>
#include <map>
#include <functional>

class Wrapper
{
public:
	/// <summary>
	/// Wrapper constructor
	/// </summary>
	/// <typeparam name="baseClass">the class in which the method is stored</typeparam>
	/// <typeparam name="...Args">arguments</typeparam>
	/// <param name="instance"an instance of the class over whose method you want to make a wrapper></param>
	/// <param name="method">method for which you want to make a wrapper</param>
	/// <param name="arguments">default arguments and their names</param>
	template <typename baseClass, typename... Args>
	Wrapper(baseClass* instance, int(baseClass::* method)(Args...), std::vector<std::pair<std::string, int>> arguments)
	{
		if (sizeof...(Args) != arguments.size())
			throw std::exception("too few or too many arguments");

		for (auto const& arg : arguments)
		{
			this->arguments.insert(arg);
		}

		func = [this, instance, method](std::vector<int> args)
		{
			return (call(instance, method, args, std::make_index_sequence<sizeof...(Args)>{}));
		};
	}

	/// <summary>
	/// method call with passed arguments
	/// </summary>
	/// <param name="arguments">arguments passed to the method</param>
	/// <returns>method execution result</returns>
	int funcExecute(std::map<std::string, int> arguments)
	{
		std::vector<int> args;

		if (arguments.size() != this->arguments.size())
			throw std::exception("too few or too many arguments");

		for (auto const& arg : this->arguments)
		{
			auto const& value = arguments.find(arg.first);
			if (value == arguments.end())
				throw std::exception("argument not found");

			args.push_back(value->second);
		}

		return func(args);
	}

private:
	std::map<std::string, int> arguments;
	std::function<int(std::vector<int>)> func;

	template<typename baseClass, typename Meth, size_t... Is>
	int call(baseClass* bc, Meth method, std::vector<int> argVec, std::index_sequence<Is...>)
	{
		return ((bc->*method)(argVec[Is]...));
	}
};