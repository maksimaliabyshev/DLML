#pragma once
#include "common.h"

//should actually do something with this at some point lol
struct ModInfo
{
	std::string ModPath;
	std::wstring ModName;
	std::string ModAuthor = "Unknown Author";
	std::string ModDescription = "No Description";
	std::string ModVersion = "Unknown Version";
	bool IsEnabled = 0;
	bool WasInitialized = 0;
	int ModType = 0;
	//pak: 0, rpack: 1, asi/dll:2
};

extern std::vector<ModInfo> ModInfoList;

void IndexPaks();
void LoadDlls();