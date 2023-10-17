#include <iostream>
#include <fstream>
#include <sstream>

#include "Tokenizer.h"


void PrintTokens(const std::vector<Token>& tokens)
{
    for (const Token& token : tokens)
        std::cout << token;
    std::cout << '\n';
}

std::string OpenFile()
{
    std::string program;
    std::fstream program_file;

    std::string filePath = "application/examples/test.py";

    if (filePath.size() >= 3 && filePath.substr(filePath.size() - 3) == ".py")
    {
        program_file.open(filePath, std::ios::in);
        if (program_file.is_open())
        {
            std::stringstream buffer;
            buffer << program_file.rdbuf();
            program = buffer.str();
        }
        else
            std::cerr << "Error opening file." << std::endl;
    }
    else
        std::cerr << "Invalid file extension. Only .py files are allowed." << std::endl;

    return program;
}


int main()
{
    std::string program = OpenFile();
    
    Tokenizer tokenizer;
    std::vector<Token> number_tokens = tokenizer.TokenizeNumber(program);
    PrintTokens(number_tokens);
    std::vector<Token> string_tokens = tokenizer.TokenizeString(program);
    PrintTokens(string_tokens);
    std::vector<Token> char_tokens = tokenizer.TokenizeChar(program);
    PrintTokens(char_tokens);
    std::vector<Token> comment_tokens = tokenizer.TokenizeComment(program);
    PrintTokens(comment_tokens);
    std::vector<Token> reserved_word_tokens = tokenizer.TokenizeReservedWord(program);
    PrintTokens(reserved_word_tokens);
    std::vector<Token> operator_tokens = tokenizer.TokenizeOperator(program);
    PrintTokens(operator_tokens);
    std::vector<Token> delimiter_tokens = tokenizer.TokenizeDelimiter(program);
    PrintTokens(delimiter_tokens);
    std::vector<Token> identifier_tokens = tokenizer.TokenizeIdentifier(program);
    PrintTokens(identifier_tokens);

    return 0;
}
