#pragma once

#include <regex>
#include <vector>

#include "Token.h"
#include "Searcher.h"


class Tokenizer
{
public:
    Tokenizer()
        : searcher()
    {
    }

    std::vector<Token> TokenizeNumber(std::string program);
    std::vector<Token> TokenizeString(std::string program);
    std::vector<Token> TokenizeChar(std::string program);
    std::vector<Token> TokenizeComment(std::string program);
    std::vector<Token> TokenizeReservedWord(std::string program);
    std::vector<Token> TokenizeOperator(std::string program);
    std::vector<Token> TokenizeDelimiter(std::string program);
    std::vector<Token> TokenizeIdentifier(std::string program);

private:
    std::vector<Token> Tokenize(std::string program, std::regex pattern, TokenType type, uint32_t group_id);

private:
	std::vector<Token> tokens;
    Searcher searcher;
};
