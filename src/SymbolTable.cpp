#include "SymbolTable.h"
#include <iostream>
using namespace std;
void SymbolTable::insert(string name,string type,string value){
    table[name]={type,value};
}

bool SymbolTable::exists(string name) {
    return table.find(name) != table.end();
}

void SymbolTable::update(string name,string value){
    if(table.count(name)){
        table[name].value=value;
    }
}

int SymbolTable::getInt(string name)
{
    Variable var = get(name);
    return stoi(var.value);
}

Variable SymbolTable::get(string name) {
    return table[name];
}