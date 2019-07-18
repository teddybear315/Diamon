#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "Essentials.h"

#define boolean bool

std::vector<std::string> tokens;

/* Lexes a file for parsing */
void lex(std::vector<char> fileData) {
	std::string tok, str;
	boolean inString = false;

	for (char character : fileData) {
		tok += character;
		if (tok._Equal(" ") && !inString) tok = "";
		
		else if (tok._Equal("\"") || tok._Equal("\'")) {
			if (!inString) {
				inString = true;
			} else {
				tokens.push_back("STR:" + str);
				inString = false;
				str = "";
				tok = "";
			}

		} else if (tok._Equal("prnt")) {
			tokens.push_back("PRNT");
			tok = "";

		} else if (inString) {
			str += character;
			tok = "";
		}

	}

	std::cout << joinVctr(tokens) << std::endl;
}