#pragma once
#include <wincrypt.h>
#include <string>
namespace cidia
{
	class v8
	{
		//CryptQueryObject
		//BOOL(__stdcall* CryptQueryObject)(DWORD dwObjectType, const void* pvObject, DWORD dwExpectedContentTypeFlags, DWORD dwExpectedFormatTypeFlags, DWORD dwFlags, DWORD* pdwMsgAndCertEncodingType, DWORD* pdwContentType, DWORD* pdwFormatType, HCERTSTORE* phCertStore, HCRYPTMSG* phMsg, const void** ppvContext);
		
		//bool __fastcall* CryptQueryObject(DWORD dwObjectType, const void* pvObject, DWORD dwExpectedContentTypeFlags, DWORD dwExpectedFormatTypeFlags, DWORD dwFlags, DWORD* pdwMsgAndCertEncodingType, DWORD* pdwContentType, DWORD* pdwFormatType, HCERTSTORE* phCertStore, HCRYPTMSG* phMsg, const void** ppvContext);
	public:
		std::nullptr_t closesocket(v8 a);
		std::uint64_t override_qword(std::uint64_t base_address, int offset, std::string value);
		std::uint64_t get_base_address(LPCWSTR MODULE);
		void Nop(int offset, std::uint64_t address);
		void change_bytes(int offset, unsigned char* patch, std::uint64_t address);
		void messegse_box(LPCWSTR msg, LPCWSTR info);
		void exit_process(int exit_code);
	private:
	};
}

