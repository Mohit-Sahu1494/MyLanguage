#pragma once
#include <string>
#include <unordered_map>

using namespace std;

struct Variable {
    string type;
    string value;
};

class SymbolTable {
private:
    unordered_map<string, Variable> table;

public:
    void insert(string name, string type, string value);
    bool exists(string name);
    Variable get(string name);
    void update(string name, string value);
    void print();
};