// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "v8.h"


void ResetEvent(HMODULE hObject)
{
    typedef char* (__fastcall* is_hooked)(HMODULE a);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xAD8096);
    execute_hook(hObject);
}
void SetEvent(HMODULE hObject)
{
    typedef char* (__fastcall* is_hooked)(HMODULE a);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xAD8085);
    execute_hook(hObject);
}

#define print(format, ...) fprintf (stderr, format, __VA_ARGS__)
DWORD WINAPI Main(LPVOID prm)
{
    cidia::v8::adhesive().Nop(0x39903C8, cidia::v8::adhesive().get_adhesive_address());
    cidia::v8::adhesive().Nop(0x39905F8, cidia::v8::adhesive().get_adhesive_address());
    HMODULE hObject = cidia::v8::adhesive().Get_Object(0x39896F0, L"adhesive.dll");
    SetEvent(hObject);
    ResetEvent(hObject);
    /*
    setevent 0xAD8085
    */

//resetevent

   // adhesive->messegse_box(L"test", L"fuck fivem");
   // adhesive->exit_process(0x0);
    //adhesive->Nop(0x9157D0, adhesive->get_adhesive_address());
    //adhesive->Nop(0x39903C8, adhesive->get_adhesive_address());//118836B = IDidntDoNothing Imports from ros-patches-five.dll 
    //adhesive->Nop(0x118836B, adhesive->get_adhesive_address());//30F8726
   // adhesive->Nop(0x30F8726, adhesive->get_adhesive_address());//33A8DB0 = ReportEventW
    //adhesive->Nop(0x39905F8, adhesive->get_adhesive_address());//0x39905F8 = class fwEvent<bool *> ConHost::OnShouldDrawGui Imports from conhost-v2.dll
   // adhesive->Nop(0xC60319, adhesive->get_adhesive_address());//0xC60319 = void (__stdcall *GetSystemInfo)(LPSYSTEM_INFO lpSystemInfo)
    //adhesive->Nop(0x33A8DB0, adhesive->get_adhesive_address());// bypass shoutdown socket
    FreeLibraryAndExitThread((HMODULE)prm, 0);

    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Main, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

