#include <iostream>
#include <dlfcn.h>
#include <filesystem>
#include <thread>
#include <chrono>

void loadAndExecute(const std::string &libPath)
{
    void *handle = dlopen(libPath.c_str(), RTLD_NOW);
    if (!handle)
    {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return;
    }

    void (*sayHello)();
    *(void **)(&sayHello) = dlsym(handle, "sayHello");

    if (!sayHello)
    {
        std::cerr << "Error finding symbol: " << dlerror() << std::endl;
        dlclose(handle);
        return;
    }

    sayHello();

    dlclose(handle);
}

int main()
{
    std::string libPath = "./libdynamic.dylib";
    std::filesystem::file_time_type lastWriteTime;

    while (true)
    {
        auto currentWriteTime = std::filesystem::last_write_time(libPath);

        if (currentWriteTime != lastWriteTime)
        {
            lastWriteTime = currentWriteTime;
            std::cout << "Detected change in library. Reloading..." << std::endl;
            loadAndExecute(libPath);
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}