#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

int main(int varc, char** vars) {

	std::vector<std::string> cmdVars;
	for (int i = 0; i < varc; ++i) cmdVars.push_back(vars[i]);
	
	if (varc < 2) {
		std::cout << "Usage: " << cmdVars[0] << " <path-to-diamon-script>";
		std::cin.get();
		return 9;
	}

	std::ifstream script(cmdVars[1]);

	for (std::string line; std::getline(script, line);) {
		std::cout << line << std::endl;
	}

	std::cin.get();
	return 0;

}