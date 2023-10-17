#include "Token.h"


std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    os << "<" << obj.lexeme << ", " << obj.TokenTypeToString(obj.type) << "> \t" << "Line: " << obj.line << std::endl;
    return os;
}


std::string Token::TokenTypeToString(const TokenType& type) const
{
    switch (type) {
    case TokenType::NUMBER: return "NUMBER";
    case TokenType::STRING: return "STRING";
    case TokenType::CHAR: return "CHAR";
    case TokenType::COMMENT: return "COMMENT";
    case TokenType::RESERVED_WORD: return "RESERVED_WORD";
    case TokenType::OPERATOR: return "OPERATOR";
    case TokenType::DELIMITER: return "DELIMITER";
    case TokenType::IDENTIFIER: return "IDENTIFIER";
    default: return "UNKNOWN";
    }
}
