#include "string.h"


string::string() {
    this->string_value_ = new char[11];
    char cont[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    for ( int i = 0; i < 11; i++ ){
      this->string_value_[i] = cont[i];
    }
}

char string::getChar(int i){
  return this->string_value_[i];
}

//Student A



//Student B
/*
string::string(string c_string){



}
int length(){



}

int max_size(){



}

void resize(int size_t, char char_){



}

operator=(const string&){



}

operator+(const string&, char char_){



}*/

//Student C
