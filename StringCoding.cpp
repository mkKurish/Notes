#include "StringCoding.h"

std::string convertUTF8(std::string source) {
	std::wstring wResult;
	int wLength = MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), NULL, 0);
	wResult.resize(wLength);
	MultiByteToWideChar(CP_ACP, 0, source.c_str(), -1, &wResult[0], wLength);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8Conv;
	return utf8Conv.to_bytes(wResult);
}

std::string unconvertUTF8(std::string source) {
	std::wstring wTemp;
	int wLength = MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), NULL, 0);
	wTemp.resize(wLength);
	MultiByteToWideChar(CP_UTF8, 0, source.c_str(), source.size(), &wTemp[0], wLength);
	std::string result;
	result.resize(wLength);
	WideCharToMultiByte(1251, 0, &wTemp[0], wLength, &result[0], wLength, 0, 0);
	return result;
}