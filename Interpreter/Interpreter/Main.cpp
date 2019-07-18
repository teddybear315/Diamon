#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Essentials.h"

int main(int varc, char** vars) {

	std::vector<std::string> cmdVars;
	for (int i = 0; i < varc; ++i) cmdVars.push_back(vars[i]);

	if (varc < 2) {
		std::cout << "Usage: " << cmdVars[0] << " <path-to-diamon-script>";
		return 9;
	}

	lex(getFileData(cmdVars[1])); // lex the provided file

	return 0;

}