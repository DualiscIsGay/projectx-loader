#include "api.h"
#include <conio.h>
#pragma warning(disable:4996)

std::string auth_api::api = "http://mem0ry.alphabot.online/api/";
std::string auth_api::token = "";

std::string GetCPUID() {
	int CPUInfo[4] = { -1 };
	__cpuidex(CPUInfo, 0, 0);
	if (CPUInfo[0] < 4)
		return ""; //nibba gave error no good
	std::stringstream st;
	for (int i = 0; i <= 3; i++) {
		st << CPUInfo[i];
	}
	return st.str();
}

bool auth_api::login(std::string m_username, std::string m_password, std::string m_hwid) {
	if (m_hwid == "meme") m_hwid = GetCPUID();
	
	http::post_data values = {
		{"username", base64_encode(c_aesar::encipher(base64_encode(m_username), 8))},
		{"password", base64_encode(c_aesar::encipher(base64_encode(m_password), 8))},
		{"hwid", base64_encode(c_aesar::encipher(base64_encode(m_hwid), 8))}
	};

	std::string result = base64_decode(c_aesar::decipher(base64_decode(http::post(api + "handle.php?m=a", values)->text), 8));

	if (result == "") 
	{
		MessageBox(0, L"empty_response", L"", MB_OK);
		return false;
	}
	else if (result == "empty_username")
	{
		MessageBox(0, L"empty_username", L"", MB_OK);
		return false;
	}
	else if (result == "invalid_username")
	{
		MessageBox(0, L"invalid_username", L"", MB_OK);
		return false;
	}
	else if (result == "empty_password")
	{
		MessageBox(0, L"empty_password", L"", MB_OK);
		return false;
	}
	else if (result == "wrong_password")
	{
		MessageBox(0, L"wrong_password", L"", MB_OK);
		return false;
	}
	else if (result == "no_sub")
	{
		MessageBox(0, L"no_sub", L"", MB_OK);
		return false;
	}
	else if (result == "wrong_hwid")
	{
		MessageBox(0, L"wrong_hwid", L"", MB_OK);
		return false;
	}
	else if(result.find("logged_in") != std::string::npos)
	{
		std::vector<std::string> x_x = x_spliter::split(result, '|');
		token = x_x[1];

		return true;
	}
	else {
		MessageBox(0, L"unknown_response", L"", MB_OK);
		return false;
	}
}
  
char* auth_api::dll() {
	return (char*)http::post(api + "download.php", http::post_data{ {"t", base64_encode(c_aesar::encipher(base64_encode(token), 8))} })->text.c_str();
}