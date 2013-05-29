#include <iostream>

const int MY_GLOBAL_CONST = 0;

__attribute__((always_inline)) inline void HelloWorld()
{
    std::cout<<"Hello world"<<std::endl;
}

int main()
{
    HelloWorld();
}
