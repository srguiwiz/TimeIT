#include <iostream>
#include <sstream>
#include <utility>
#include <libtimeit/exceptions/db_exception.h>

namespace libtimeit
{

using namespace std;

db_exception::db_exception(string message_, int return_code_):
	message(move(message_)),
	return_code(return_code_)
{
}

const char *db_exception::what() const noexcept
{
	stringstream str;
	str << rc_to_string() << " " << message.c_str() << endl;
	static std::string result = str.str();
	return result.c_str();
}

std::string db_exception::rc_to_string() const
{
	stringstream str;
	str << "Error ";
	if (return_code > 0)
	{
			str << return_code;
	}
	return str.str();
}

}