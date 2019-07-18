#include <vector>
#include <string>

#pragma once

extern std::vector<std::string> tokens;

std::vector<std::string> splitBySpace(std::string input);
std::vector<char> getFileData(std::string filename);
std::string joinVctr(std::vector<std::string> vector);
std::string joinVctr(std::vector<std::string> vector, std::string delimeter);

/* LEXER */
void lex(std::vector<char> fileData);

/* PARSER */
void parser(std::vector<std::string> lexedTokens);