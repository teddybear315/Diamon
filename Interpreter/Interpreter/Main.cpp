#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <fstream>

#include "Essentials.h"

int main(int varc, char** vars) {

	std::vector<std::string> cmdVars;
	for (int i = 0; i < varc; ++i) cmdVars.push_back(vars[i]);

	if (varc < 2) {
		std::cout << "Usage: " << cmdVars[0] << " <path-to-diamon-script>";
		return 9;
	}

	bool logging = false;
	std::string logFile = "";

	if (varc > 2) {
		for (std::string var : cmdVars) {
			if (!var.compare(0, std::string("--log=").size(), "--log=")) {
				var.erase(var.begin(), var.begin() + 6);
				logging = true;
				logFile = var;
			}
		}
	}

	lex(getFileData(cmdVars[1])); // lex the provided file
	parser(tokens, logging, logFile);

	return 0;

}