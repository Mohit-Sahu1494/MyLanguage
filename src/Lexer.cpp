#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "Token.h"
#include <typeinfo>
#include "lexer.h"

using namespace std;

unordered_set<string> keyWords = {
    "int",
    "char",
    "float",
    "string",
    "print",
    "ask",
    "bool",
    "true",
    "false",
    "end",
};

unordered_set<string> operators = {
    "+",
    "-",
    "*",
    "/",
    "=",
    "(",
    ")",
    ",",
};

unordered_set<string> lineterminated = {
    ";"};
    //  int num = 10


Lexer::Lexer(const std::string &sourceCode){

    this->sourceCode = sourceCode;
    currentIndex = 0;
}

int Lexer::peek(){
    return sourceCode[currentIndex];
}

int Lexer::Advance(){
    return sourceCode[currentIndex++];
}

bool Lexer::isAtEnd()
{
    return currentIndex >= sourceCode.length();
}



//  read variable name
void Lexer::readIdentifier(){
    string word;

    while (!isAtEnd() && (isalnum(peek()) || peek() == '_')) {
        word += Advance();
    }
    Token token;

    if (keyWords.count(word))
        token.type = TokenType::Keyword;
    else
        token.type = TokenType::Identifier;

    token.value = word;

    tokens.push_back(token);
}

//  yah number ko read karta hai

void Lexer::readNumber()
{
    int num = 0;

    while (!isAtEnd() && isdigit(peek()))
    {
        int digit = Advance() - '0';
        num = num * 10 + digit;
    }

    Token token;
    token.type = TokenType::Numbers;    
    token.value = to_string(num);
    tokens.push_back(token);
}



//  yah string ko read karta hai
void Lexer::readString(){
    string str;
     
    // Opening quote (")
    Advance();

    while (!isAtEnd() && peek() != '"')
    {
        str += Advance();
    }

    // Closing quote (")
    if (!isAtEnd())
    {
        Advance();
    }

    Token token;
    token.type = TokenType::String;   // ya TokenType::String agar alag enum hai
    token.value = str;

    tokens.push_back(token);
}

void Lexer::readCharacters()
{
    Advance(); // Opening '

    if (isAtEnd())
        return;

    char ch = Advance();

    if (peek() != '\'')
    {
        cout << "Error: Invalid character literal\n";
        return;
    }

    Advance();

    Token token;
    token.type = TokenType::Chars;
    token.value = string(1, ch);

    tokens.push_back(token);
}



void Lexer::readOperator()
{
    string opr;
    opr += Advance();

    Token token;
    token.type = TokenType::Operator;
    token.value = opr;

    tokens.push_back(token);
}



vector<Token> Lexer::tokenize(){
  while (!isAtEnd())
{
    if (isspace(peek()))
    {
        Advance();
    }
    else if (isalpha(peek()) || peek() == '_')
    {
        readIdentifier();
    }
    else if (isdigit(peek()))
    {
        readNumber();
    }
    else if (peek() == '"')
    {
        readString();
    }
    else if (peek() == '\'')
    {
        readCharacters();
    }
    else if (operators.count(string(1, peek())))
    {
        readOperator();
    }
else if (peek() == ';')
{
    Advance();

    Token token;
    token.type = TokenType::Semicolon;
    token.value = ";";

    tokens.push_back(token);
}    else
    {
        cout << "Unknown Character : " << peek() << endl;
        Advance();
    }
}

// for (auto &t : tokens)
// {
//     cout << t.value << endl;
// }
return tokens;
}
