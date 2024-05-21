#include <iostream>

extern "C"
{
    void sayHello()
    {
        // std::cout << "Hello from the dynamically loaded library!" << std::endl;
        std::cout << "Hello from the dynamically loaded library updated!" << std::endl;
    }
}