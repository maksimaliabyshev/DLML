#pragma once
#include <windows.h> 
#include <vector>
#include <string>

struct ModInfo
{
	std::string ModPath;
	std::wstring ModName;
	std::string ModAuthor = "Unknown Author";
	std::string ModDescription = "No Description";
	std::string ModVersion = "Unknown Version";
	bool IsEnabled = 0;
	bool IsRpack = 0;
	bool WasInitialized = 0;
};
std::string str_tolower(std::string s);

void IndexPaks();
extern std::vector<ModInfo> ModInfoList;