#pragma once
#include <string>

#ifdef DLL2_EXPORTS
#define DLL2_API __declspec(dllexport)
#else
#define DLL2_API __declspec(dllimport)
#endif

extern "C" DLL2_API std::string Encrypt(std::string str, int key);
extern "C" DLL2_API std::string Decrypt(std::string str, int key);