#pragma once
#include <vector>
#include<unordered_map>
#include "Token.h"
#include "SymbolTable.h"


class Parser {
private:
    std::vector<Token> tokens;
    int current = 0;
    SymbolTable symbolTable;
      bool hasError = false;  


public:
       Parser(std::vector<Token> tokens);
    void parse();

private:
    Token peek();
    Token advance();
    bool isAtEnd();
   bool match(TokenType expectedType, std::string expectedValue);
void parseDeclaration();
void parseProgram();
 void parseAssignment();
 void parsePrint();
  void parseInput();
  void error(string message,string data);
  int parseExpression();
  int parseTerm();
  int parseFactor();
 string tokenTypeToString(TokenType type);
 int parseTypeOfVariable(string variableName);
 };