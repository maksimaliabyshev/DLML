#pragma once
#include <cstdio>
#include <iostream>
#include <windows.h>
#include "MinHook/MinHook.h"
#include "ModLoader.h"
#include "Menu.h"
#include "Logger.h"

bool __cdecl Add_Source_Hook(char const* Path, int FFSAddSourceFlags);
bool __cdecl LoadPack_Hook(__int64 something, const char* path, bool Param, bool Param2, bool Param3, __int64 ResorcePackHandle);
bool __cdecl OpenPack_Hook(void* ResorceDataPack, const char* path, UINT Param);
__int64 __cdecl CResourceDataPack_Hook(void* dis);

void __cdecl InitializeGameScript_Hook(LPCSTR param_1);

void __cdecl CLogV_Hook(int logtype, char* thread, char* sourcefile, int linenumber, int CLFilterAction, int CLLineMode, char const* __ptr64 message, char const* __ptr64 printarg);
//annoying ahh

int __cdecl GetCategoryLevel_Hook(int This, char* Catagory);

extern FARPROC InitializeGameScript_Address;
extern FARPROC LoadPack_Address;
extern FARPROC OpenPack_Address;
extern FARPROC CResourceDataPack_Address;
extern FARPROC Add_Source_Address;
extern FARPROC CLogV_Address;
extern FARPROC GetCategoryLevel_Address;

BOOL WINAPI CreateHooks(HMODULE hmodule);