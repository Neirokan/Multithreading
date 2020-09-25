#include "global_lab_header.hpp"
#include <string>

namespace utility
{
	bool has_extension(const std::string& str)
	{
		size_t sep = str.find_last_of("\\/");
		size_t dot = str.find_last_of('.');
		return (dot != str.npos) && (sep == str.npos || dot > sep);
	}
}
