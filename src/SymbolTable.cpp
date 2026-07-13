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

Variable SymbolTable::get(string name) {
    return table[name];
}
void SymbolTable::print() {
    cout<<"table size :- "<<table.size()<<endl;
    for (auto &var : table) {
        cout << "Name  : " << var.first <<endl;
        cout << "Type  : " << var.second.type << endl;
        cout << "Value : " << var.second.value << endl;
        cout << "------------------------" << endl;
    }
}
