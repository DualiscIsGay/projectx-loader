#include "api.h"
#include <iostream>
#include <fstream>

int main()
{
	std::string username, password;

	std::cout << "Username :\n";
	std::cin >> username;
	std::cout << "Password :\n";
	std::cin >> password;

	if (auth_api::login(username, password)) {
		MessageBox(0, L"success", L"", MB_OK);
	}
	else {

	}

}