
#include <iostream> 
#include <windows.h> 


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Error: Invalid argument count. Exiting the program...";
        return -1;
    }
    else
    {
        std::cout << "File name: " << argv[1] << "\nAppendable character: " << argv[2] << std::endl;
    }

    HMODULE hDll = LoadLibrary("FileProcessingDll.dll");
    if (!hDll)
    {
        std::cerr << "Failed to load library" << std::endl;
        return GetLastError();
    }

    void (*ProcessFile)(std::string, char*) = (void (*)(std::string, char*))GetProcAddress(hDll, "ProcessFile");
    if (!ProcessFile)
    {
        std::cerr << "Failed to get ProcessFile procedure address from DLL.";
        return GetLastError();
    }

    ProcessFile(argv[1], argv[2]);

    return 0;
}