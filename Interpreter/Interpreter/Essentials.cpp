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
	if (!file) return std::vector<char>();
	std::vector<char> tokens;

	for (std::string line; std::getline(file, line);) {
		for (int character = 0; character < line.length(); ++character)
			tokens.push_back(line[character]);
		tokens.push_back('\\');
		tokens.push_back('n');
	}

	return tokens;
}

/* Turns a vector into a string */
std::string joinVctr(std::vector<std::string> vector) {
	return joinVctr(vector, ", ");
}

/* Turns a vector into a string with delemiter inbetween each value */
std::string joinVctr(std::vector<std::string> vector, std::string delimeter) {
	std::stringstream ss;
	for (size_t i = 0; i < vector.size(); ++i) {
		if (i != 0) ss << delimeter;
		ss << vector[i];
	}
	return(ss.str());
}

std::string print(std::string str, bool logging, std::fstream& logFile) {
	std::string tok;
	if (!logging) {
		for (char character : str) {
			tok += character;
			if (tok._Equal("\n")) { std::cout << std::endl; tok = ""; }
			else if (tok._Equal("\\")) { std::cout << "\\"; tok = ""; }
			else { std::cout << tok; tok = ""; }
		}
	} else {
		for (char character : str) {
			tok += character;
			if (tok._Equal("\n")) { logFile << '\n'; tok = ""; }
			else if (tok._Equal("\\")) { logFile << "\\"; tok = ""; }
			else { logFile << tok; tok = ""; }
		}
	}
	return str;
}