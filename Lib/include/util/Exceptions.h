#pragma once

#include <exception>
#include <string>

class NotImplementedException : public std::exception
{
public:
	char* what() {
		return "Missing implementation";
	}
};