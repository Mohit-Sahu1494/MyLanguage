#include "Lexer.h"
#include "Parser.h"
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main() {

    ifstream file("second.my");

    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();

    string sourceCode = buffer.str();
    Lexer lexer(sourceCode);

    vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    parser.parse();

    return 0;
}

 
