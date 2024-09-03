#include "pch.h" 
#include <windows.h> 
#include <iostream> 
#include <fstream> 
#include <string> 

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD  dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) void ProcessFile(std::string fileName, char* replacementChar)
{
    std::ifstream inputFile(fileName);
    std::ofstream outputFile("output.txt");
    std::string buff;
    while (getline(inputFile, buff))
    {
        for (char& ch : buff)
        {
            if (ch == '.' || ch == ',' || ch == ';' || ch == ':' || ch == '!' ||
                ch == '?' || ch == '\'' || ch == '\"' || ch == '-' || ch == '(' ||
                ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
            {
                ch = replacementChar[0];
            }
        }
        outputFile << buff << std::endl;
    }

    inputFile.close();
    outputFile.close();
    std::cout << "File processed successfully. Check \"output.txt\" for result." << std::endl;
}
