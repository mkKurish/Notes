#pragma once
#include <codecvt>
#include <Windows.h>
#include <string>

/*
This is necessary for the correct storage of the Cyrillic alphabet in files.
Converts utf-8 string to CP_ACP and writes to string again
*/
static std::string convertUTF8(std::string source) {
	std::wstring wResult;
	int wLength = MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), NULL, 0);
	wResult.resize(wLength);
	MultiByteToWideChar(CP_ACP, 0, source.c_str(), -1, &wResult[0], wLength);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8Conv;
	return utf8Conv.to_bytes(wResult);
}

/*
This is necessary for the correct reading of Cyrillic letters from files.
Translates a utf-8 string into a wide utf-8 string, and then reads a wide string into a 1251-cp string
*/
static std::string unconvertUTF8(std::string source) {
	std::wstring wTemp;
	int wLength = MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), NULL, 0);
	wTemp.resize(wLength);
	MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), &wTemp[0], wLength);
	std::string result;
	result.resize(wLength);
	WideCharToMultiByte(1251, 0, &wTemp[0], wLength, &result[0], wLength, 0, 0);
	return result;
}