#pragma once
#include<string>
enum class TokenType {
    Keyword,
    Identifier,
    String,
    Chars,
    Numbers,
    Assign,
    Operator,
    Semicolon,
    EndOfFile,
};

class Token{
public:
    TokenType type;
    std::string value;
};
