#pragma once
#include <string>
#include <iostream>


enum class TokenType
{
    NUMBER,
    STRING,
    CHAR,
    COMMENT,
    RESERVED_WORD,
    OPERATOR,
    DELIMITER,
    IDENTIFIER,
};


struct Token
{
    std::string lexeme;
    TokenType type;
    uint32_t line;

    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
    std::string TokenTypeToString(const TokenType& type) const;
};
