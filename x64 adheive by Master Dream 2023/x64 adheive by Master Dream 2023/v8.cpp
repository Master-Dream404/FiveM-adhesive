#include "pch.h"
#include "v8.h"

// this was made like 10 days in 2023 so all offsets needs to be updated

cidia::v8& cidia::v8::adhesive()
{
    static cidia::v8 instance;
    return instance;
}

void cidia::v8::print_vf(const std::string& msg)
{
    typedef char* (__fastcall* is_hooked)(const std::string&, const std::string&);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"conhost-v2.dll") + 0x2FA90);
    execute_hook("Cidia::v8", msg + "\n");
}

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
    execute_hook(a);
}

std::uint64_t cidia::v8::do_not_close_socket()
{
    //15D1670
    cidia::v8::Nop(0x15D1670, cidia::v8::get_adhesive_address());
}



void cidia::v8::messegse_box(LPCWSTR msg, LPCWSTR info)
{
    //30F8748
    typedef char* (__fastcall* is_hooked)(HWND, LPCWSTR, LPCWSTR, UINT);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0x30F8748);
    execute_hook(0, msg, info, 0);
}

HMODULE cidia::v8::Get_Object(int offset, LPCWSTR module_)
{
    HMODULE data = (HMODULE)(GetModuleHandle(module_) + offset);
    return data;
}

std::string cidia::v8::getqword_data_string(int offset, LPCWSTR module_)
{
    std::string* data = (std::string*)(GetModuleHandle(module_) + offset);
    return data->c_str();
}

void cidia::v8::SetConsoleMode(HANDLE hConsoleHandle, DWORD dwMode)
{
    typedef char* (__fastcall* is_hooked)(HANDLE, DWORD);
    is_hooked execute_hook = (is_hooked)((uintptr_t)GetModuleHandle(L"adhesive.dll") + 0x9811FE);//981493
    execute_hook(hConsoleHandle, dwMode);
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
    std::string a = *(std::string*)GetModuleHandle(module_);
    cidia::v8::print_vf(a);
    return (std::uint64_t)GetModuleHandleW(module_);
}

std::uint64_t cidia::v8::get_adhesive_address()
{
    return (std::uint64_t)GetModuleHandle(L"adhesive.dll");
}

void cidia::v8::Nop(int offset, std::uint64_t address)
{
    void* addr = (void*)(address + offset);

    DWORD old;

    unsigned char nop[1]{0x90};
    std::string msg = *(std::string*)addr;
    msg.append(" replaced by Nop : 0x90");
    cidia::v8::print_vf(msg);
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
