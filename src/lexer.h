#pragma once

#include<string>
#include<vector>
#include "Token.h"

class Lexer {
    private:
      std:: string sourceCode;
      size_t currentIndex;
      std::vector<Token> tokens;
    public:
    Lexer(const std::string& sourceCode);
    std::vector<Token> tokenize();
    int peek();
    int Advance();
    bool isAtEnd();
    void readIdentifier();
    void readNumber();
    void readString();
    void readCharacters();
    void readOperator();
    // void readSemiColons();
};
