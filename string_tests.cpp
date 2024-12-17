#include <cstdlib>
#include <iostream>
#include <type_traits>

#include "string.h"

int main(){
    string a = string();
    for (int i = 0 ; i < a.size() ; i++) {
        std::cout << a.getChar(i);
    }
    std::cout << std::endl;

    string b = a; // copy constructor
    for (int i = 0; i < b.size() ; i++) {
        std::cout << b.getChar(i);
    }
    std::cout << std::endl;

    char* c = b.c_str(); // c_str() member function
    std::cout << "String b to c_str: " << c << std::endl;

    std::cout << "The size of string b is " << b.size() << std::endl; // size() member function

    b.clear();
    std::cout << "Strings cleared." << std::endl;
    std::cout << "String b cleared: " << std::endl;
    for (int i = 0; i < b.size() ; i++) {
        std::cout << b.getChar(i);
    }
    std::cout << std::endl;
    
    string d;
    d = 'D';
    std::cout << "Usage of = operator: " << std::endl;
    std::cout << "d = ";
    for (int i = 0; i < d.size() ; i++) {
        std::cout << d.getChar(i);
    }
    std::cout << std::endl;

    string e;
    e = e + " How are you?";
    std::cout << "Usage of + operator: " << std::endl;
    std::cout << "(Hello world) + (How are you?) = ";
    for (int i = 0; i < e.size() ; i++) {
        std::cout << e.getChar(i);
    }
    std::cout << std::endl;

    
}

