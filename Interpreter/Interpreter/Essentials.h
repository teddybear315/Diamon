#include <vector>
#include <string>

#pragma once

std::vector<std::string> splitBySpace(std::string input);
std::vector<char> getFileData(std::string filename);

/* LEXER */
void lex(std::vector<char> fileData);