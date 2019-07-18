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
	std::string error = "none";

	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "PRNT") {
			if (i + 1 >= tokens.size())
				error = errors[EXPECTED_PARAMETER];
			else if (tokens[i + 1].compare(0, std::string("STR").size(), "STR"))
				error = errors[EXPECTED_STRING];
			if (error != "none") { std::cout << error << i + 1 << std::endl; return; }

			i++;
			tokens[i].erase(tokens[i].begin(), tokens[i].begin() + 4);
			std::cout << tokens[i] << std::endl;
		}
	}
	
}