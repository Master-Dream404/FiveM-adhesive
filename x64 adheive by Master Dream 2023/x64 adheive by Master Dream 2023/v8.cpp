#include "pch.h"
#include "v8.h"

std::uint64_t cidia::v8::override_qword(std::uint64_t base_address, int offset, std::string value)
{
    std::uint64_t base_address_ = base_address;

    std::uint64_t qword = *(std::uint64_t*)(base_address_ + offset);

    std::uint64_t a1 = *(std::uint64_t*)(qword + 0x10);

    *(std::uint64_t*)(a1 + 0x10) = (std::uint64_t)&value;

    return a1;
}

std::nullptr_t cidia::v8::closesocket(v8 a)
{
    typedef char* (__fastcall* is_hooked)(v8 b);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xA70E21);
    execute_hook(a);//you need to find the a value like is it https://fivem//socket to close the con
}

void cidia::v8::messegse_box(LPCWSTR msg, LPCWSTR info)
{
    //30F8748
    typedef char* (__fastcall* is_hooked)(HWND, LPCWSTR, LPCWSTR, UINT);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0x30F8748);
    execute_hook(0, msg, info, 0);//you need to find the a value like is it https://fivem//socket to close the con
}

void cidia::v8::exit_process(int exit_code)
{
    //D28F01
    typedef char* (__fastcall* is_hooked)(int);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0xD28F01);
    execute_hook(exit_code);
    
}

std::uint64_t cidia::v8::get_base_address(LPCWSTR module_)
{
    return (std::uint64_t)GetModuleHandleW(module_);
}

void cidia::v8::Nop(int offset, std::uint64_t address)
{
    void* addr = (void*)(address + offset);

    DWORD old;

    unsigned char nop[1]{0x90};
    VirtualProtect(addr, sizeof(nop), PAGE_EXECUTE_READWRITE, &old);
    memcpy(addr, nop, sizeof(nop));
    VirtualProtect(addr, sizeof(nop), old, &old);
}

void cidia::v8::change_bytes(int offset, unsigned char* patch, std::uint64_t address)
{
    void* addr = (void*)(address + offset);

    DWORD old;

    VirtualProtect(addr, sizeof(patch), PAGE_EXECUTE_READWRITE, &old);
    memcpy(addr, patch, sizeof(patch));
    VirtualProtect(addr, sizeof(patch), old, &old);
}