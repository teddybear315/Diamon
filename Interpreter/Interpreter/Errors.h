#include <string>
#include <vector>

#pragma once

enum ERRORS {
	EXPECTED_PARAMETER = 0,
	EXPECTED_STRING = 1
};

/* remember to pass token number */
extern std::vector<std::string> errors;