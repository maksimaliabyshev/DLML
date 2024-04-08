// dllmain.cpp : Defines the entry point for the DLL application.
#include "common.h"
#include "Hooks.h"
#include "global.h"

HMODULE dsound_dll;

/* This Should be a lot better. It will also allow debugging and it doesn't use asm */
auto oDirectSoundCaptureCreate = (decltype(DirectSoundCaptureCreate)*)nullptr;
HRESULT WINAPI DirectSoundCaptureCreate(_In_opt_ LPCGUID pcGuidDevice, _Outptr_ LPDIRECTSOUNDCAPTURE* ppDSC, _Pre_null_ LPUNKNOWN pUnkOuter)
{
	return oDirectSoundCaptureCreate(pcGuidDevice, ppDSC, pUnkOuter);
}

auto oDirectSoundCaptureCreate8 = (decltype(DirectSoundCaptureCreate8)*)nullptr;
HRESULT WINAPI DirectSoundCaptureCreate8(_In_opt_ LPCGUID pcGuidDevice, _Outptr_ LPDIRECTSOUNDCAPTURE8* ppDSC8, _Pre_null_ LPUNKNOWN pUnkOuter)
{
	return oDirectSoundCaptureCreate8(pcGuidDevice, ppDSC8, pUnkOuter);
}

auto oDirectSoundCaptureEnumerateA = (decltype(DirectSoundCaptureEnumerateA)*)nullptr;
HRESULT WINAPI DirectSoundCaptureEnumerateA(_In_ LPDSENUMCALLBACKA pDSEnumCallback, _In_opt_ LPVOID pContext)
{
	return oDirectSoundCaptureEnumerateA(pDSEnumCallback, pContext);
}

auto oDirectSoundCaptureEnumerateW = (decltype(DirectSoundCaptureEnumerateW)*)nullptr;
HRESULT WINAPI DirectSoundCaptureEnumerateW(_In_ LPDSENUMCALLBACKW pDSEnumCallback, _In_opt_ LPVOID pContext)
{
	return oDirectSoundCaptureEnumerateW(pDSEnumCallback, pContext);
}

auto oDirectSoundCreate = (decltype(DirectSoundCreate)*)nullptr;
_Check_return_ HRESULT WINAPI DirectSoundCreate(_In_opt_ LPCGUID pcGuidDevice, _Outptr_ LPDIRECTSOUND* ppDS, _Pre_null_ LPUNKNOWN pUnkOuter)
{
	return oDirectSoundCreate(pcGuidDevice, ppDS, pUnkOuter);
}

auto oDirectSoundCreate8 = (decltype(DirectSoundCreate8)*)nullptr;
HRESULT WINAPI DirectSoundCreate8(_In_opt_ LPCGUID pcGuidDevice, _Outptr_ LPDIRECTSOUND8* ppDS8, _Pre_null_ LPUNKNOWN pUnkOuter)
{
	return oDirectSoundCreate8(pcGuidDevice, ppDS8, pUnkOuter);
}

auto oDirectSoundEnumerateA = (decltype(DirectSoundEnumerateA)*)nullptr;
HRESULT WINAPI DirectSoundEnumerateA(_In_ LPDSENUMCALLBACKA pDSEnumCallback, _In_opt_ LPVOID pContext)
{
	return oDirectSoundEnumerateA(pDSEnumCallback, pContext);
}

auto oDirectSoundEnumerateW = (decltype(DirectSoundEnumerateW)*)nullptr;
HRESULT WINAPI DirectSoundEnumerateW(_In_ LPDSENUMCALLBACKW pDSEnumCallback, _In_opt_ LPVOID pContext)
{
	return oDirectSoundEnumerateW(pDSEnumCallback, pContext);
}

auto oDirectSoundFullDuplexCreate = (decltype(DirectSoundFullDuplexCreate)*)nullptr;
HRESULT WINAPI DirectSoundFullDuplexCreate(_In_opt_ LPCGUID pcGuidCaptureDevice,_In_opt_ LPCGUID pcGuidRenderDevice,_In_ LPCDSCBUFFERDESC pcDSCBufferDesc,_In_ LPCDSBUFFERDESC pcDSBufferDesc,HWND hWnd,DWORD dwLevel,_Outptr_ LPDIRECTSOUNDFULLDUPLEX* ppDSFD,_Outptr_ LPDIRECTSOUNDCAPTUREBUFFER8* ppDSCBuffer8,_Outptr_ LPDIRECTSOUNDBUFFER8* ppDSBuffer8,_Pre_null_ LPUNKNOWN pUnkOuter)
{
	return oDirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter);
}

auto oGetDeviceID = (decltype(GetDeviceID)*)nullptr;
HRESULT WINAPI GetDeviceID(_In_opt_ LPCGUID pGuidSrc, _Out_ LPGUID pGuidDest)
{
	return oGetDeviceID(pGuidSrc, pGuidDest);
}

auto oDllCanUnloadNow = (decltype(DllCanUnloadNow)*)nullptr;
__control_entrypoint(DllExport) STDAPI  DllCanUnloadNow(void)
{
	return oDllCanUnloadNow();
}

auto oDllGetClassObject = (decltype(DllGetClassObject)*)nullptr;
_Check_return_ STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv)
{
	return oDllGetClassObject(rclsid, riid, ppv);
}

void setup_dsound() {
	oDirectSoundCaptureCreate = (decltype(DirectSoundCaptureCreate)*)GetProcAddress(dsound_dll, "DirectSoundCaptureCreate");
	oDirectSoundCaptureCreate8 = (decltype(DirectSoundCaptureCreate8)*)GetProcAddress(dsound_dll, "DirectSoundCaptureCreate8");
	oDirectSoundCaptureEnumerateA = (decltype(DirectSoundCaptureEnumerateA)*)GetProcAddress(dsound_dll, "DirectSoundCaptureEnumerateA");
	oDirectSoundCaptureEnumerateW = (decltype(DirectSoundCaptureEnumerateW)*)GetProcAddress(dsound_dll, "DirectSoundCaptureEnumerateW");
	oDirectSoundCreate = (decltype(DirectSoundCreate)*)GetProcAddress(dsound_dll, "DirectSoundCreate");
	oDirectSoundCreate8 = (decltype(DirectSoundCreate8)*)GetProcAddress(dsound_dll, "DirectSoundCreate8");
	oDirectSoundEnumerateA = (decltype(DirectSoundEnumerateA)*)GetProcAddress(dsound_dll, "DirectSoundEnumerateA");
	oDirectSoundEnumerateW = (decltype(DirectSoundEnumerateW)*)GetProcAddress(dsound_dll, "DirectSoundEnumerateW");
	oDirectSoundFullDuplexCreate = (decltype(DirectSoundFullDuplexCreate)*)GetProcAddress(dsound_dll, "DirectSoundFullDuplexCreate");
	oGetDeviceID = (decltype(GetDeviceID)*)GetProcAddress(dsound_dll, "GetDeviceID");
	oDllCanUnloadNow = (decltype(DllCanUnloadNow)*)GetProcAddress(dsound_dll, "DllCanUnloadNow");
	oDllGetClassObject = (decltype(DllGetClassObject)*)GetProcAddress(dsound_dll, "DllGetClassObject");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		(void)DisableThreadLibraryCalls(hModule);

		if (_DEBUG) {
			(void)AllocConsole();

			(void)freopen("CONOUT$", "w", stderr);
			(void)freopen("CONOUT$", "w", stdout);
		}

		MH_STATUS status = MH_Initialize();
		std::string statusCode = MH_StatusToString(status);

		if (status != MH_OK && status != MH_ERROR_ALREADY_INITIALIZED) {
			MsgBoxExit(MB_ICONERROR, "Exiting", "Unable to initialize MinHook: %p", statusCode);
		}
		globals.MinHookInitialized = true;

		char path[MAX_PATH]{};
		(void)CopyMemory(path + GetSystemDirectory(path, MAX_PATH - 12), "\\dsound.dll", 12);
		dsound_dll = LoadLibrary(path);

		if (dsound_dll == NULL)
			(void)MsgBoxExit(MB_ICONERROR, "Exiting", "Source dsound.dll missing");

		(void)setup_dsound();

		HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CreateHooks, hModule, 0, 0);
		if (handle != 0)
		{
			(void)SetThreadPriority(handle, 2);
			(void)CloseHandle(handle);
		}

		break;
	}
	case DLL_PROCESS_DETACH:
	{
		(void)FreeLibrary(dsound_dll);
		(void)MH_Uninitialize();

		if (_DEBUG) {
			(void)FreeConsole();
		}
	}
	break;
	}
	return TRUE;
}
