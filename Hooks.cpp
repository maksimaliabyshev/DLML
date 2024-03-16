﻿#include "Hooks.h"
#include <algorithm>
//#include "TestHook.h"

typedef bool(*add_source)(char const* __ptr64, int FFSAddSourceFlags);
add_source Add_Source;
bool Add_Source_Hook(char const* Path, int FFSAddSourceFlags) {
	bool Status = Add_Source(Path, FFSAddSourceFlags);

	const char* thread = "DLML ResPack";
	if (Status == true) {
		std::string message = "Added Source: " + (std::string)Path + " SourceFlag: " + std::to_string(FFSAddSourceFlags) + "\n";
		Log(message);
	}

	return Status;
}

/* public: bool __cdecl IGame::LoadPack(class ttl::string_base<char> const & __ptr64,bool,bool,struct IGame::SRPackHandle * __ptr64 * __ptr64) __ptr64 */
/* public: enum EResPackErrorCode::ENUM __cdecl CResourceDataPack::LoadData(bool) __ptr64 */
/* ENUM __thiscall CResourceDataPack::LoadData(CResourceDataPack *this,bool param_1) */ 


/* string_base<char> *pathmostlikely,bool param_2,bool param_3, SRPackHandle **param_4 */
typedef bool(*loadpack)(__int64 something, const char* path, bool Param, bool Param2, bool Param3, __int64 ResorcePackHandle);
loadpack LoadPack;

bool LoadPack_Hook(__int64 something, const char* path, bool Param, bool Param2, bool Param3, __int64 ResorcePackHandle) {
	//AddLog("ResorceDataPack :  %p\n", (void*)CResourceDataPack1);
	//AddLog("ResorceDataPack1 :  %p\n", (void*)ResorceDataPack);
	Log(path);
	return LoadPack(something, path, Param, Param2, Param3, ResorcePackHandle);
}


typedef bool(*openpack)(void* ResorceDataPack, const char* path, UINT Param); //might be UINT Param); , with 0x40000000 
openpack OpenPack;

bool OpenPack_Hook(void* ResorceDataPack, const char* path, UINT Param) {
	AddLog("ResorceDataPack2 :  %p\n", (void*)ResorceDataPack);
	return OpenPack(ResorceDataPack, path, Param);
}


typedef void*(*cresourcedatapack)(void* dis);
cresourcedatapack CResourceDataPack;
void* CResourceDataPack_Hook(void* dis) {
	return CResourceDataPack(dis);
}

/*
__int64 CResourceDataPack1 = (__int64)GetProcAddress(EngineDll, "??0CResourceDataPack@@QEAA@XZ");
OpenPack openPack = (OpenPack)GetProcAddress(EngineDll, "?OpenPack@CResourceDataPack@@QEAA?AW4ENUM@EResPackErrorCode@@PEBDI@Z");
LoadData loadPack = (LoadData)GetProcAddress(EngineDll, "?LoadData@CResourceDataPack@@QEAA?AW4ENUM@EResPackErrorCode@@_N@Z");

openPack(CResourceDataPack1, "DW\\Data\\static_load_PC.rpack", 1);
loadPack(CResourceDataPack1, 1);
*/			


//getting Messi 
/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢉⣉⣉⣹⣿⣿⣭⡍⣉⡉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢹⣯⡍⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣯⣿⣿⣿⣿⣿⣿⣶⣭⣢⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣶⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣷⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡯⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⢊⠡⣿⣿⣿⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣿⡿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⢀⢃⠳⣹⣿⣿⢯⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢳⣻⣷⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⢌⢢⣱⢹⣿⣯⢟⣿⣿⣿⣥⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣯⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⢌⠢⣉⠖⣻⣿⣿⣿⣿⣿⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠈⢻⣿⡂⠀⠀⠀⠀⠀⠠⣠⢠⢌⡰⢎⡱⡰⢈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⠟⠀⠀⠀⠈⢿⢳⣄⠀⠀⢀⣤⣤⡐⢡⢚⣿⣯⡓⣥⠓⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠤⠈⠙⡄⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⡽⣿⡿⣿⡽⠟⡌⠻⣿⣿⡆⠀⠀⠀⠀⢻⣋⣿⠀⠀⣾⡿⣟⠃⠆⣭⠦⠿⢲⣌⢿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠱⠲⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⢨⣿⣿⣿⣿⡽⣹⠣⠝⠿⠉⠀⠀⠀⠐⣿⢱⡀⠀⠀⠀⡏⢳⣿⠀⠀⣾⣱⣟⣿⠿⠁⠀⠘⠥⣚⣬⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⢠⡧⠀⠐⣦⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⢳⡘⠡⠂⠀⠀⠀⠀⠀⠀⠀⠓⠛⠀⠀⠀⠀⠀⢹⣿⠀⠐⣿⡿⡈⠌⠄⠀⠀⠀⣣⢘⡾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢅⣹⣿⠃⠀⢀⠈⠒⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡯⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⡏⢧⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⣿⣷⢍⠒⠀⠀⠀⠠⡐⠪⣝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢋⣀⡀⠟⠀⠀⠁⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠈⠔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣷⣅⠀⢀⡽⣿⡧⠀⠀⠀⢀⠐⢨⡑⠾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⣶⣿⣇⠀⣄⣧⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡁⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢉⣿⣿⣿⡀⢸⣿⡿⠇⠀⠀⠀⠠⠑⠂⡌⢓⡒⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⣼⣿⠋⠀⡅⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡌⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠁⣸⣟⢩⣿⣭⠶⣿⠀⠀⠀⠀⠀⠡⢉⠐⢂⠂⠜⣠⢛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⡿⠋⠲⣤⣵⣄⣀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣿⡿⡃⢻⣿⠐⣻⠀⠀⠀⠀⠀⠁⠈⠄⠁⢈⠐⠄⢪⣙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⣶⣿⣿⣿⣿⣿⣶⣄⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡗⡇⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⢃⡇⢸⣿⡠⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⡐⢬⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀⣧⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⢻⡇⢰⣿⡳⣽⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⢢⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡀⢻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⣽⡇⠈⢻⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢐⠠⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡙⠄⠈⠫⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢩⣀⣀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠂⠄⡡⢂⣍⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠐⡀⠀⠀⠻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠉⢿⡛⠇⠀⠀⠀⠀⠀⠀⠀⠠⢁⠎⠴⣙⣾⣿⣿⣿⣿⣿⠟⣿⣛⣿⢻⣟⠿⣿⣿⣿⠿⢣⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣧⠀⠀⠀⠀⠀⠀⠀⠀⠐⡨⢌⢣⣿⣿⣿⣿⣿⣿⣿⣟⣳⣛⡞⡓⠜⡉⢓⠘⠋⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢠⢦⡟⠁⡀⠀⠀⠀⠀⠀⠀⠀⢀⠖⣨⢾⣿⣿⣿⣿⣿⣿⣿⢶⡳⢖⠨⢘⠠⠁⡀⠀⣰⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠭⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣡⣸⣷⢠⠅⡀⠀⠀⠀⠀⠀⠀⢌⡚⣴⢯⣿⣿⣿⣿⣿⣿⢯⢦⡱⢈⠂⠀⠀⠂⠀⣴⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡟⠡⠂⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⢘⡯⣿⣿⣿⡇⠎⠀⠀⠀⠀⠀⠀⡌⢢⣝⣺⣻⢿⣿⣿⣿⣿⣿⣽⢂⠆⡡⢈⠀⠀⠀⣸⣿⣿⣿⣯⣿⡷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠃⠄⠀⠀⠀⠀⠀⠀⠀⠡⢀⠀⠀⠀⠀⠀⠀⠸⡇⢾⣯⠛⢿⠂⠀⠀⠀⠀⠀⠒⣬⢳⣭⢷⡽⣿⣻⣿⣿⣿⣿⢟⡢⡘⢀⠀⠀⠀⣶⣿⣿⡿⣿⣿⣿⣿⣿⡟⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⢀⡇⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠄⠀⠀⠀⠀⠀⣯⣿⠃⠀⠐⡷⠀⠀⠀⠀⢨⡱⢎⣷⣯⣿⢿⡿⣿⣿⣿⣿⣿⢯⡱⠌⣂⠐⠀⣰⣿⣿⣿⡷⣿⣿⣿⣿⡟⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢌⣠⣀⠀⠀⣨⣿⠏⠀⠀⠀⢳⠀⠀⠀⣄⢳⡼⣟⣾⣷⣿⣻⣿⣷⣿⣿⣿⣿⢶⡡⢎⠀⠘⢰⣿⣿⣿⣿⣿⣻⣿⣽⡟⠁⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⠛⠻⠿⠟⠁⠀⠀⠀⠀⣨⣧⣤⣣⣌⣿⣿⣯⣿⣿⣽⣿⣿⣿⣻⣿⣿⣽⣯⠴⣈⠂⣠⣿⣿⣿⣿⣿⡿⣿⣿⣟⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣇⡀⠂⠀⠀⠀⢀⣠⠔⠲⠿⢽⢷⣿⣽⣟⡿⣿⣿⣿⣿⣿⣻⡿⣽⣿⣿⣿⣘⠢⢄⢡⣿⣿⣿⣿⣿⣿⣛⣿⣿⠋⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⡏⠉⠢⣖⠾⡿⠿⠟⠀⠀⠀⠀⠀⠙⣿⣾⣿⣿⣿⣿⣿⡿⣷⣿⣿⣿⣿⣳⢫⠐⢂⣾⣿⣿⣿⣿⣿⣿⣯⣿⡏⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠁⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⢿⣿⡇⠀⠀⠈⠳⡑⠒⠁⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⢯⣿⣟⡷⣿⣿⣯⡻⡽⢀⢲⣿⣿⣿⣿⣿⣿⣿⢿⣿⠁⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣀⣀⣀⣀⣀⣀⣀⣀⣈⣦⣄⣀⣀⣀⣀⣀⣠⣠⣤⣾⣫⣾⣿⣇⣀⣀⣠⣄⣤⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣿⣿⣿⣿⣻⣜⣻⣼⣳⣿⣫⣕⣸⣀⣿⣿⣿⣿⣿⣿⣾⣿⣿⣧⣠⣀⣀⣀⣀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*/








typedef void* (*allocandloadpack)(void* param_1, const char* param_2);
allocandloadpack AllocAndLoadPack;
void* AllocAndLoadPack_Hook(void* param_1, const char* param_2) {
	AddLog("param_1 :  %x\n", (void*)param_1);
	AddLog("param_2 :  %x\n", (void*)param_2);

	return AllocAndLoadPack(param_1, param_2);
}


/*bool PackLoader::Load(undefined8 param_1,undefined8 somesortofpath,undefined8 *CResourceDataPack,
                     undefined8 param_4,undefined8 param_5,int param_6,int param_7)
					 

	fs::full_path((char *)&local_78)
	iVar7 = loadrpack(param_1,pcVar11,param_3,uVar1,0);
	fs::exists and malloc abunch
	CResourceDataPack::OpenPack

	this is also the same func that the game uses, as shown in alot of log messages
	looks like this gets the path, loads it into mem, then calls openpack

	kinda like my attempt earlier
	void* buffthing = malloc(0xd0);
	OpenPack_Hook(buffthing, ModInfoList[i].ModPath.c_str(), 0x10);
	but like actually good as this is more like
	EngineDll + 0x412e70


	looks like it takes the name of the pack it wants to load and searches for it and any others with the same type
	like textures_pc.rpack textures_0_pc.rpack textures_1_pc.rpack 
	with                                                                               
    PackLoader::Load(param_1[0x15f],"common_textures",uVar12,0,in_stack,uVar35, uVar16,uVar34);
	but also I beleve we can point it to a folder to search for such as


	puVar27 = SomeFunction(local_4c8,"DW/Data/common_textures_%d",iVar9);

	if (*puVar27 != NULL) {
		puVar32 = *puVar27;
	}                                                                                 
    PackLoader::Load(param_1[0x15f],puVar32,uVar12,0,in_stack,uVar35,uVar16,uVar34);

*/
typedef void* (*packloaderload)(void* param_1, const char* maybepath, void* CResourceDataPack, __int64 param_4, __int64 param_5, int param_6, int param_7);
packloaderload PackLoaderLoad;
void* PackLoaderLoad_Hook(void* param_1, const char* maybepath, void* CResourceDataPack, int param_4, __int64 param_5, int param_6, int param_7) {
	AddLog("SomeAddress :  %p\n", param_1); //not sure how this is used, but it is used and it does not change
	AddLog("maybepath :  %s\n", maybepath); //going to try "Mods/Rpacks/common_textures_%d"
	AddLog("CResourceDataPack PackLoaderLoad_Hook :  %p\n", CResourceDataPack);//maybe just alloc memory or just malloc(0xd0); like before
	AddLog("param_4 :  %i\n", param_4); //0
	AddLog("param_5 :  %p\n", param_5); //0
	AddLog("param_6 :  %i\n", param_6); //0
	AddLog("param_7 :  %i\n", param_7); //1
	return PackLoaderLoad(param_1, maybepath, CResourceDataPack, param_4, param_5, param_6, param_7);
}


typedef bool (*fspathpath)(const char* BasePath, const char* SubPath, bool option);
fspathpath FsPathPath;
bool FsPathPath_Hook(const char* BasePath, const char* SubPath, bool option) {
	//AddLog("bas :  %s\n", BasePath);
	//AddLog("sub :  %s\n", SubPath);
	//AddLog("bool :  %s\n", std::to_string(option));
	return FsPathPath(BasePath, SubPath, option);
}

typedef bool (*fsexist)(const char* SubPath);
fsexist FsExist;
bool FsExist_Hook(const char* SubPath) {
	AddLog("FsExist SubPath :  %s\n", SubPath);
	bool fsexist = FsExist(SubPath);

	AddLog("FsExist Ret :  %s\n", std::to_string(fsexist));
	return fsexist;
}


typedef bool(*alternativeloadpack)(void* something, const char* path, void* CResourceDataPack, UINT param_4, char* param_5);
alternativeloadpack AlternativeLoadPack;

//ENUM loadrpack(longlong* param_1, char* PathMostLikely, CResourceDataPack** CResourceDataPack,uint param_4, char* param_5)

bool AlternativeLoadPack_Hook(void* something, const char* path, void* CResourceDataPack, UINT param_4, char* param_5) {
	//AddLog("ResorceDataPack :  %p\n", (void*)CResourceDataPack1);
	//AddLog("ResorceDataPack1 :  %p\n", (void*)ResorceDataPack);
	//Log(path);
	return AlternativeLoadPack(something, path, CResourceDataPack, param_4, param_5);
}


typedef void(__cdecl* initializegamescript)(LPCSTR param_1);
initializegamescript InitializeGameScript = nullptr;
void InitializeGameScript_Hook(LPCSTR param_1) {

	//HMODULE EngineDll = GetModuleHandleA("engine_x64_rwdi.dll");
	//__int64 CResourceDataPack1 = (__int64)GetProcAddress(EngineDll, "??0CResourceDataPack@@QEAA@XZ");

	for (size_t i = 0; i < ModInfoList.size(); i++)
		if (ModInfoList[i].IsRpack) {

			//void* buffthing = malloc(0xd0);
			//OpenPack_Hook(buffthing, ModInfoList[i].ModPath.c_str(), 0x10);
			//LoadPack_Hook(ModInfoList[i].ModPath.c_str(), true, true, true, (__int64)buffthing);
			//buffthing = static_cast<char*>(buffthing) + 8;
			//LoadData_Hook(buffthing, false);
			//void* pvVar4 = malloc(0x1040);

			void* Param_1 = NULL; //void* pvVar41 = malloc(0x1040);
			void* CResourceDataPack = NULL; //void* CResourceDataPack = malloc(0xd0);
			const char* Path = ModInfoList[i].ModPath.c_str();
			const char* thread = "DLML ResPack";

			bool Param6 = false;
			bool Param7 = true;

			UINT uVar6 = 0x102;
			if (Param6 != 0) {
				uVar6 = 0x100;
			}
			UINT uVar1 = uVar6 | 0x200;
			if (Param7 != 0) {
				uVar1 = uVar6;
			}

			int iVar7 = AlternativeLoadPack_Hook(Param_1, Path, CResourceDataPack, uVar1, 0);
			Log(std::to_string(iVar7) + "\n");
			if (iVar7 < 0) { //Fail State                  
				if (iVar7 == -8) {
					Log("mid af\n");
					//Log(LogType::ERRR, thread, "Already loaded | %s.\n");//, Path, true);
				}
				else {
					bool bVar5 = FsExist_Hook(Path);
					if (bVar5) {
						Log("bad2\n");
						//Log(LogType::ERRR, thread, "FAILED         | %s not loaded (version incorrect?).\n");//, Path, true);
					}
					else {
						Log("bad3\n");
						//Log(LogType::ERRR, thread, "Missing        | %s is missing.\n");//, Path, true);
					}
				}

			}
			else {
				Log("good\n");
				//Log(LogType::ERRR, thread, "Loaded         | %s.\n");//, Path, true);
			}
			//void* buffthing = malloc(0xd0);
			//const char* path = ModInfoList[i].ModPath.c_str();
			//FsExist_Hook((char*)path);
			//PackLoaderLoad_Hook(NULL, "../../Mods/Rpacks/common_textures_%d", NULL, 0, 0, 0, 1);
			//PackLoaderLoad_Hook(NULL, "../../Mods/Rpacks/common_textures_%d", NULL, 0, 0, 1, 1);
			//PackLoaderLoad_Hook(NULL, "../../Mods/Rpacks/common_textures_%d", NULL, 0, 0, 1, 0);
			//PackLoaderLoad_Hook(NULL, "../../Mods/Rpacks/common_textures_%d", NULL, 0, 0, 0, 0);

			//void* pvVar41 = malloc(0x1040);

			//void* buffthing1 = malloc(0xd0);

			//PackLoaderLoad_Hook(pvVar41, ModInfoList[i].ModPath.erase(ModInfoList[i].ModPath.length() - 9, ModInfoList[i].ModPath.length()).c_str(), buffthing1, 0, 0, 0, 1);

		}
		else
		{
			Add_Source_Hook(ModInfoList[i].ModPath.c_str(), 9);
		}

	Log((std::string)"Initializing Game Scripts\n");
	return InitializeGameScript(param_1);
}

typedef void(__cdecl* _clogv)(LogType LogType, char* thread, char* sourcefile, int linenumber, int CLFilterAction, int CLLineMode, char const* __ptr64 message, char const* __ptr64 printarg);
_clogv CLogV = nullptr;
void CLogV_Hook(int logtype, char* thread, char* sourcefile, int linenumber, int CLFilterAction, int CLLineMode, char const* __ptr64 message, char const* __ptr64 printarg) {
	std::string Message;

	//this is a really bad rn

	if (logtype == LogType::DEBG)
		Message.append(" DBUG :");
	else if (logtype == LogType::WARN)
		Message.append(" WARN :");
	else if (logtype == LogType::INFO)
		Message.append(" INFO :");
	else if (logtype == LogType::ERRR)
		Message.append(" ERRR :");

	Message.append(" [" + (std::string)thread + "] ");

#ifdef DEBUG //this is so old bruh I need to get mfin deeebug workin but it doesn't like how I did dllproxyin 
	printf(">%s(%d): ", sourcefile, linenumber);
#endif
	if (CLFilterAction == 2)
		Message.append("| ");
	else
		Message.append("> ");

	char Buffer[65528];
	vsprintf(Buffer, message, (va_list)printarg);
	Message.append(Buffer);
	AddLog(Message.c_str());
	return CLogV((LogType)logtype, thread, sourcefile, linenumber, CLFilterAction, CLLineMode, message, printarg);
}

typedef int(*getcategorylevel)(int This, char* Catagory);
getcategorylevel GetCategoryLevel;
int GetCategoryLevel_Hook(int This, char* Catagory) { //GetCategoryLevel
	//Log(param_1);
	//int Status = Function(NULL, param_1);
	return INT_MAX;
}

//whatever
FARPROC InitializeGameScript_Address;
FARPROC LoadPack_Address;
FARPROC AllocAndLoadPack_Address;
FARPROC OpenPack_Address;
FARPROC CResourceDataPack_Address;
FARPROC PackLoaderLoad_Address;
FARPROC FsPathPath_Address;
FARPROC FsExist_Address;
FARPROC AlternativeLoadPack_Address;

FARPROC Add_Source_Address;
FARPROC CLogV_Address;
FARPROC GetCategoryLevel_Address;

BOOL CreateHooks(HMODULE hmodule) {
	HMODULE EngineDll = GetModuleHandleA("engine_x64_rwdi.dll");
	HMODULE FilesystemDll = GetModuleHandleA("filesystem_x64_rwdi.dll");

	AddLog("\nFound engine_x64_rwdi.dll BaseAddress at :  %p\n", (void*)EngineDll);
	AddLog("Found filesystem_x64_rwdi.dll BaseAddress at :  %p\n", (void*)FilesystemDll);

	InitializeGameScript_Address = GetProcAddress(EngineDll, "InitializeGameScript");
	LoadPack_Address = GetProcAddress(EngineDll, "?LoadPack@IGame@@QEAA_NAEBV?$string_base@D@ttl@@_N1PEAPEAUSRPackHandle@1@@Z");//LoadData is used for rpack patching instead of using "?LoadPack@IGame@@QEAA_NAEBV?$string_base@D@ttl@@_N1PEAPEAUSRPackHandle@1@@Z"); like the game does
	OpenPack_Address = GetProcAddress(EngineDll, "?OpenPack@CResourceDataPack@@QEAA?AW4ENUM@EResPackErrorCode@@PEBDI@Z");
	CResourceDataPack_Address = GetProcAddress(EngineDll, "??0CResourceDataPack@@QEAA@XZ");
	AllocAndLoadPack_Address = (FARPROC)((DWORD_PTR*)EngineDll + 0x412e70 / (2 * sizeof(DWORD)));
	PackLoaderLoad_Address = (FARPROC)((DWORD_PTR*)EngineDll + 0x401870 / (2 * sizeof(DWORD)));
	AlternativeLoadPack_Address = (FARPROC)((DWORD_PTR*)EngineDll + 0x400460 / (2 * sizeof(DWORD)));

	FsPathPath_Address = GetProcAddress(FilesystemDll, "??0path@fs@@QEAA@PEBD_N@Z");
	FsExist_Address = GetProcAddress(FilesystemDll, "?exists@fs@@YA_NPEBD@Z");

	Add_Source_Address = GetProcAddress(FilesystemDll, "?add_source@fs@@YA_NPEBDW4ENUM@FFSAddSourceFlags@@@Z");
	CLogV_Address = GetProcAddress(FilesystemDll, "?_CLogV@@YAXW4TYPE@ELevel@Log@@PEBD1HW4ENUM@CLFilterAction@@W44CLLineMode@@1PEAD@Z");
	GetCategoryLevel_Address = GetProcAddress(FilesystemDll, "?GetCategoryLevel@Settings@Log@@QEBA?AW4TYPE@ELevel@2@PEBD@Z");

	if (MH_CreateHook(InitializeGameScript_Address, &InitializeGameScript_Hook, reinterpret_cast<void**>(&InitializeGameScript)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create InitializeGameScript hook at location: %p"), InitializeGameScript_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(LoadPack_Address, &LoadPack_Hook, reinterpret_cast<void**>(&LoadPack)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create LoadPack hook at location: %p"), LoadPack_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(OpenPack_Address, &OpenPack_Hook, reinterpret_cast<void**>(&OpenPack)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create OpenPack hook at location: %p"), OpenPack_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(CResourceDataPack_Address, &CResourceDataPack_Hook, reinterpret_cast<void**>(&CResourceDataPack)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create CResourceDataPack hook at location: %p"), CResourceDataPack_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(AllocAndLoadPack_Address, &AllocAndLoadPack_Hook, reinterpret_cast<void**>(&AllocAndLoadPack)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create AllocAndLoadPack hook at location: %p"), AllocAndLoadPack_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(PackLoaderLoad_Address, &PackLoaderLoad_Hook, reinterpret_cast<void**>(&PackLoaderLoad)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create PackLoaderLoad hook at location: %p"), PackLoaderLoad_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}

	/*
	if (MH_CreateHook(FsPathPath_Address, &FsPathPath_Hook, reinterpret_cast<void**>(&FsPathPath)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create FsPathPath hook at location: %p"), FsPathPath_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	*/
	if (MH_CreateHook(FsExist_Address, &FsExist_Hook, reinterpret_cast<void**>(&FsExist)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create FsExist hook at location: %p"), FsExist_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(AlternativeLoadPack_Address, &AlternativeLoadPack_Hook, reinterpret_cast<void**>(&AlternativeLoadPack)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create AlternativeLoadPack hook at location: %p"), AlternativeLoadPack_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}




	if (MH_CreateHook(Add_Source_Address, &Add_Source_Hook, reinterpret_cast<void**>(&Add_Source)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create Add_Source hook at location: %p"), Add_Source_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(CLogV_Address, &CLogV_Hook, reinterpret_cast<void**>(&CLogV)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create CLogV hook at location: %p"), CLogV_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}
	if (MH_CreateHook(GetCategoryLevel_Address, &GetCategoryLevel_Hook, reinterpret_cast<void**>(&GetCategoryLevel)) != MH_OK)
	{
		std::string errorMessage = std::string("Unable to create GetCategoryLevel hook at location: %p"), GetCategoryLevel_Address;
		Log(errorMessage);
		throw std::runtime_error(errorMessage);
	}

	//CreateTestHook();

	IndexPaks();
	MH_EnableHook(MH_ALL_HOOKS);

	bool init_hook = false;
	do
	{
		if (Directx11_Hook() == Status::Success)
		{
			if (::GetModuleHandle("dxgi.dll") != NULL && ::GetModuleHandle("d3d11.dll") != NULL)
			{
				bind(8, (void**)&oPresent, hkPresent);
				bind(13, (void**)&oResizeBuffers, hkResizeBuffers); //gota get that Resizeable Buffalo
				init_hook = true;
			}
		}

	} while (!init_hook);

	//need to do this like, good
	while (true) {
		Sleep(100);
		if (GetAsyncKeyState(VK_DELETE))
			break;
	}

	return true;
}