#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "Essentials.h"
#include "Errors.h"

#define boolean bool

void parser(std::vector<std::string> lexedTokens, bool logging, std::string logFile) {
	
	std::fstream logger(logFile, std::ios::out | std::ios::binary);

	std::vector<std::string> tokens = lexedTokens;
	std::string error;
	std::string printOut;
	int lineNumber = 1;

	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "PRINT") {
			if (tokens[i + 1] == "\\n")
				error = errors[EXPECTED_PARAMETER];
			else if (tokens[i + 1].compare(0, std::string("STR").size(), "STR"))
				error = errors[EXPECTED_STRING];
			if (error != std::string()) { printOut = print(error + std::to_string(lineNumber), logging, logger); return; }

			i++;
			tokens[i].erase(tokens[i].begin(), tokens[i].begin() + 4);
			printOut = print(tokens[i] + "\n", logging, logger);
		} else if (tokens[i] == "THROW") {
			if (tokens[i + 1] == "\\n")
				error = errors[EXPECTED_PARAMETER];
			else if (tokens[i + 1].compare(0, std::string("STR").size(), "STR"))
				error = errors[EXPECTED_STRING];
			if (error != std::string()) { printOut = print(error + std::to_string(lineNumber), logging, logger); return; }

			i++;
			tokens[i].erase(tokens[i].begin(), tokens[i].begin() + 4);
			printOut = print("Forced error: " + tokens[i] + " @Line " + std::to_string(lineNumber), logging, logger);
			return;
		} else if (tokens[i] == "\\n") ++lineNumber;
	}
	
}