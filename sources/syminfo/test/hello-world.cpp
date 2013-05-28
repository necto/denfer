#include <iostream>

const int MY_GLOBAL_CONST = 0;

volatile void HelloWorld()
{
    std::cout<<"Hello world"<<std::endl;
}

int main()
{
    HelloWorld();
}
