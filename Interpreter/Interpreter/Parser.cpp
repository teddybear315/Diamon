#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "Essentials.h"
#include "Errors.h"

#define boolean bool

void parser(std::vector<std::string> lexedTokens) {
	
	std::vector<std::string> tokens = lexedTokens;
	std::string error;
	int lineNumber = 1;

	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "PRINT") {
			if (tokens[i + 1] == "\\n")
				error = errors[EXPECTED_PARAMETER];
			else if (tokens[i + 1].compare(0, std::string("STR").size(), "STR"))
				error = errors[EXPECTED_STRING];
			if (error != std::string()) { std::cout << error << lineNumber << std::endl; return; }

			i++;
			tokens[i].erase(tokens[i].begin(), tokens[i].begin() + 4);
			std::cout << tokens[i] << std::endl;
		} else if (tokens[i] == "THROW") {
			if (tokens[i + 1] == "\\n")
				error = errors[EXPECTED_PARAMETER];
			else if (tokens[i + 1].compare(0, std::string("STR").size(), "STR"))
				error = errors[EXPECTED_STRING];
			if (error != std::string()) { std::cout << error << lineNumber << std::endl; return; }

			i++;
			tokens[i].erase(tokens[i].begin(), tokens[i].begin() + 4);
			std::cout << "Forced error: " << tokens[i] << " @Line " << lineNumber << std::endl;
		} else if (tokens[i] == "\\n") ++lineNumber;
	}
	
}