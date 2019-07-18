#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "Essentials.h"

#define boolean bool

/* Lexes a file for parsing */
void lex(std::vector<char> fileData) {
	std::string tok, str;
	boolean inString = false;

	for (char character : fileData) {
		tok += character;
		//std::cout << tok << std::endl;
		if (tok._Equal(" ")) tok = "";
		else if (tok._Equal("\"") || tok._Equal("\'")) {
			if (!inString) {
				inString = true;
			} else {
				str = "";
				std::cout << "Found a string" << std::endl;
				inString = false;
			}
		
		} else if (tok._Equal("prnt")) {
			std::cout << "Found a print" << std::endl;
			tok = "";
		}
		else if (inString) {
			str += character;
			tok = "";
		}

	}
}