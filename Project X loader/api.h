#include "http/utils.h"
#include "http/http.h"
#include "utils.h"
#include "base64.h"
#include "caesar.h"
#include "split.h"


class auth_api 
{
public:
    static bool login(std::string m_username, std::string m_password, std::string m_hwid = "meme");
	static char* dll();
	static std::string token;
private:
	static std::string api;
};