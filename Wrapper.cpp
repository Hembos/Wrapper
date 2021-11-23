#include "Wrapper.h"

template<class baseClass, class ...arguments>
Wrapper::Wrapper(baseClass* instance, int(baseClass::* method)(arguments...), std::vector<std::pair<std::string, int>> defaltValues)
{

}

template<class ...arguments>
Wrapper::Wrapper(int(*function)(arguments...), std::vector<std::pair<std::string, int>> defaltValues)
{

}

int Wrapper::call(std::map<std::string, int> mapArguments)
{

	return 0;
}