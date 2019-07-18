#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include "Essentials.h"

#define boolean bool

/* Splits string by space and returns the string as a vector<string> containing each "word" */
std::vector<std::string> splitBySpace(std::string input) {
	std::vector<std::string> result;
	std::istringstream iss(input);
	for (std::string s; iss >> s;) result.push_back(s);
	return result;
}

/* Opens a file and puts every line in that file into an array. */
std::vector<char> getFileData(std::string filename) {
	std::ifstream file(filename);
	std::vector<char> tokens;

	for (std::string line; std::getline(file, line);) 
		for (int character = 0; character < line.length(); ++character)
			tokens.push_back(line[character]);

	return tokens;
}