#pragma once

#include <regex>


struct Searcher
{
    Searcher()
        : number_regex(R"((#.*)|(\"[^\"\\]*(?:\\.[^\"\\]*)*\"|\'[^\'\\]*(?:\\.[^\'\\]*)*\')|(\b[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?\b|\b0x[0-9A-Fa-f]+\b))"),
        string_regex(R"((#.*)|(\"[^\"\\]*\"))"),
        char_regex(R"((#.*)|(\'[^\']*\'))"),
        comment_regex(R"(#[^\n]*)"),
        reserved_word_regex(R"((#.*)|(\"[^\"\\]*(?:\\.[^\"\\]*)*\"|\'[^\'\\]*(?:\\.[^\'\\]*)*\')|\b(range|False|class|finally|is|return|None|continue|for|lambda|try|True|def|from|nonlocal|while|and|del|global|not|with|as|elif|if|or|yield|assert|else|import|pass|break|except|in|raise)\b)"),
        operator_regex(R"((#.*)|([\+\-\*\=\%\^\&\|\>\<\~\!]))"),
        delimiter_regex(R"((#.*)|([\;\(\)\{\}\[\]\,\:\@]))"),
        identifier_regex(R"((#.*)|(([a-zA-Z_][a-zA-Z0-9_]*)\s*(=|\+=|-=|\*=|\/=)\s*))")
    {
    }

    std::regex number_regex;
    std::regex string_regex;
    std::regex char_regex;
    std::regex comment_regex;
    std::regex reserved_word_regex;
    std::regex operator_regex;
    std::regex delimiter_regex;
    std::regex identifier_regex;
};
