#include "Lexer.h"
#include "Parser.h"
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: mylang <filename>" << endl;
        return 1;
    }

    string filename = argv[1];

    ifstream file(filename);

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string source(
        (istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    parser.parse();
}