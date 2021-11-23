#include <iostream>
#include "Engine.h"
#include "SomeClass.h"

int main()
{
    SomeClass someClass;

    Wrapper wrapper(&someClass, &SomeClass::sum, { {"arg1", 0}, {"arg2", 0} });

    Engine engine;

    engine.registerCommand(&wrapper, "command1");

    std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;

    return 0;
}