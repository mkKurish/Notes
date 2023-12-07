#pragma once
#include <codecvt>
#include <Windows.h>
#include <string>

/*
This is necessary for the correct storage of the Cyrillic alphabet in files.
Converts utf-8 string to CP_ACP and writes to string again
*/
std::string convertUTF8(std::string source);

/*
This is necessary for the correct reading of Cyrillic letters from files.
Translates a utf-8 string into a wide utf-8 string, and then reads a wide string into a 1251-cp string
*/
std::string unconvertUTF8(std::string source);