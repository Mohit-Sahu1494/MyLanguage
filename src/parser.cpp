#include "parser.h"
#include "SymbolTable.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
}
Token Parser::peek()
{
    return tokens[current];
}

Token Parser::advance()
{
    if (!isAtEnd())
        current++;

    return tokens[current - 1];
}
bool Parser::isAtEnd()
{
    return current >= tokens.size();
}

void Parser::parse()
{
    parseProgram();
}
void Parser::error(string message, string data)
{
    cout << message << data << endl;
    hasError = true;
    exit(EXIT_FAILURE);
}

void Parser::parseProgram()
{

    while (!isAtEnd() && !hasError)
    {

        if (peek().type == TokenType::Keyword & peek().value == "print")
        {

            parsePrint();
        }
        else if (peek().type == TokenType::Identifier)
        {

            parseAssignment();
        }
        else if (peek().type == TokenType::Keyword)
        {
            parseDeclaration();
        }
        else
        {
            error("Unexpected Error", peek().value);
            advance();
        }
    }
}

void Parser::parseDeclaration()
{
    string dataType;
    string variableName;
    string data;
    dataType = peek().value;
    if (!(match(TokenType::Keyword, "int") ||
          match(TokenType::Keyword, "float") ||
          match(TokenType::Keyword, "char") || match(TokenType::Keyword, "string")))
    {

        cout << "Expected Data Type" << endl;
        advance();
        return;
    }
    variableName = peek().value;
    if (!match(TokenType::Identifier, peek().value))
    {
        cout << "Expected Identifier" << endl;
        return;
    }
    if (symbolTable.exists(variableName))
    {
        cout << "Variable name already declared" << endl;
        hasError = true;
        return;
    }

    if (peek().type == TokenType::Semicolon)
    {

        advance();
        string defaultValue = "";

        cout << "data type :- " << dataType << endl;

        if (dataType == "int")
            defaultValue = "0";
        else if (dataType == "float")
            defaultValue = "0.0";
        else if (dataType == "char")
            defaultValue = "'\\0'";
        else if (dataType == "string")
            defaultValue = "";
        symbolTable.insert(variableName, dataType, defaultValue);
        return;
    }

    if (!match(TokenType::Operator, "="))
    {
        cout << "Expected '='" << endl;
        return;
    }
    if (peek().type == TokenType::Keyword && peek().value == "ask")
    {

        advance(); // consume ask

        if (!match(TokenType::Operator, "("))
        {
            cout << "Expected '('" << endl;
            return;
        }

        string prompt = "";

        if (peek().type == TokenType::String)
        {
            prompt = peek().value;
            advance();
        }

        if (!match(TokenType::Operator, ")"))
        {
            cout << "Expected ')'" << endl;
            return;
        }
        if (!match(TokenType::Semicolon, ";"))
        {
            cout << "Expected ';'" << endl;
            return;
        }

        cout << prompt;

        string inputValue;
        getline(cin,inputValue);

        symbolTable.insert(variableName, dataType, inputValue);

        return;
    }

    data = peek().value;
    if (!(match(TokenType::Numbers, peek().value) ||
          match(TokenType::String, peek().value) ||
          match(TokenType::Chars, peek().value)))
    {

        cout << "Expected Data" << endl;
        return;
    }
    if (!match(TokenType::Semicolon, ";"))
    {
        cout << "Expected Semicolon" << endl;
        //  advance();
        return;
    }
    symbolTable.insert(variableName, dataType, data);
    // cout << "Variable Declaration Parsed Successfully" << endl;
}

bool Parser::match(TokenType expectedType, string expectedValue)
{
    if (!isAtEnd() &&
        peek().type == expectedType &&
        peek().value == expectedValue)
    {
        advance();
        return true;
    }

    return false;
}
void Parser::parseAssignment()
{
    string variableName = peek().value;
    match(TokenType::Identifier, variableName);
    match(TokenType::Operator, "=");
    string data = peek().value;
    match(TokenType::Numbers, data) || match(TokenType::String, data) || match(TokenType::Chars, data);

    match(TokenType::Semicolon, ";");
    if (!symbolTable.exists(variableName))
    {
        cout << "Variable not declared" << endl;
        return;
    }
    symbolTable.update(variableName, data);
}

void Parser::parsePrint()
{

    // print
    if (!match(TokenType::Keyword, "print"))
    {
        cout << "Expected 'print'" << endl;
        return;
    }

    // (
    if (!match(TokenType::Operator, "("))
    {
        cout << "Expected '('" << endl;
        return;
    }

    // Variable print

    if (peek().type == TokenType::Identifier)
    {

        string variableName = peek().value;

        if (!match(TokenType::Identifier, variableName))
        {
            cout << "Expected Identifier" << endl;
            return;
        }

        if (!symbolTable.exists(variableName))
        {
            cout << "Variable not declared" << endl;
            return;
        }

        Variable var = symbolTable.get(variableName);
        cout << var.value << endl;
    }

    // String print
    else if (peek().type == TokenType::String)
    {

        string value = peek().value;

        match(TokenType::String, value);

        cout << value << endl;
    }

    // Number print
    else if (peek().type == TokenType::Numbers)
    {

        string value = peek().value;

        match(TokenType::Numbers, value);

        cout << value << endl;
    }

    else
    {
        cout << "Invalid print argument" << endl;
        return;
    }

    // )
    if (!match(TokenType::Operator, ")"))
    {
        cout << "Expected ')'" << endl;
        return;
    }

    // ;
    if (!match(TokenType::Semicolon, ";"))
    {
        cout << "Expected ';'" << endl;
        return;
    }
}

void Parser::parseInput()
{

    // Data Type
    string dataType = peek().value;

    if (!(match(TokenType::Keyword, "int") ||
          match(TokenType::Keyword, "float") ||
          match(TokenType::Keyword, "char") ||
          match(TokenType::Keyword, "string")))
    {

        cout << "Expected Data Type" << endl;
        return;
    }

    // Identifier
    string variableName = peek().value;

    if (!match(TokenType::Identifier, variableName))
    {
        cout << "Expected Identifier" << endl;
        return;
    }

    // =
    if (!match(TokenType::Operator, "="))
    {
        cout << "Expected '='" << endl;
        return;
    }

    // ask
    if (!match(TokenType::Keyword, "ask"))
    {
        cout << "Expected 'ask'" << endl;
        return;
    }

    // (
    if (!match(TokenType::Operator, "("))
    {
        cout << "Expected '('" << endl;
        return;
    }

    // Prompt String
    string prompt = "";

    if (peek().type == TokenType::String)
    {
        prompt = peek().value;
        advance();
    }
    // )
    if (!match(TokenType::Operator, ")"))
    {
        cout << "Expected ')'" << endl;
        return;
    }

    // ;
    if (!match(TokenType::Semicolon, ";"))
    {
        cout << "Expected ';'" << endl;
        return;
    }

    // ===== Runtime Input =====

    cout << prompt;

    string inputValue;
    cin >> inputValue;

    // Store variable in symbol table
    symbolTable.insert(variableName, dataType, inputValue);

    cout << variableName << " = " << inputValue << endl;
}