#include <iostream>
#include "foo.hpp"
#include "goo.hpp"

int main()
{
    std::cout << Foo::doSomething(4, 3) << "\n";
    return (0);
}