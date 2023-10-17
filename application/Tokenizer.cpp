#include "Tokenizer.h"


std::vector<Token> Tokenizer::Tokenize(std::string program, std::regex pattern, TokenType type, uint32_t group_id)
{
    tokens.clear();
    std::smatch match;
    uint32_t line_number = 1;
    std::string line;
    size_t pos = 0;
    while ((pos = program.find('\n')) != std::string::npos)
    {
        line = program.substr(0, pos);
        program.erase(0, pos + 1);

        if (std::regex_search(line, match, pattern))
            if (match[group_id].matched)
                tokens.push_back({ match[group_id], type, line_number });

        line_number++;
    }
    return tokens;
}


std::vector<Token> Tokenizer::TokenizeNumber(std::string program)
{
    return Tokenize(program, searcher.number_regex, TokenType::NUMBER, 3);
}


std::vector<Token> Tokenizer::TokenizeString(std::string program)
{
    return Tokenize(program, searcher.string_regex, TokenType::STRING, 2);
}


std::vector<Token> Tokenizer::TokenizeChar(std::string program)
{
    return Tokenize(program, searcher.char_regex, TokenType::CHAR, 2);
}


std::vector<Token> Tokenizer::TokenizeComment(std::string program)
{
    return Tokenize(program, searcher.comment_regex, TokenType::COMMENT, 0);
}


std::vector<Token> Tokenizer::TokenizeReservedWord(std::string program)
{
    return Tokenize(program, searcher.reserved_word_regex, TokenType::RESERVED_WORD, 3);
}


std::vector<Token> Tokenizer::TokenizeOperator(std::string program)
{
    return Tokenize(program, searcher.operator_regex, TokenType::OPERATOR, 2);
}


std::vector<Token> Tokenizer::TokenizeDelimiter(std::string program)
{
    return Tokenize(program, searcher.delimiter_regex, TokenType::DELIMITER, 2);
}


std::vector<Token> Tokenizer::TokenizeIdentifier(std::string program)
{
    return Tokenize(program, searcher.identifier_regex, TokenType::IDENTIFIER, 2);
}
