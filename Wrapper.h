#include <functional>
#include <string>
#include <vector>
#include <map>

class Wrapper
{
private:
	std::map<std::string, int> argsAndDefValues;
	std::function<int(std::vector<int> const&)> func;
public:
	template<class baseClass, class... arguments>
	Wrapper(baseClass* instance, int(baseClass::* method)(arguments...), std::vector<std::pair<std::string, int>> defaltValues);

	template<class... arguments>
	Wrapper(int(*function)(arguments...), std::vector<std::pair<std::string, int>> defaltValues);

	int call(std::map<std::string, int> mapArguments);
};