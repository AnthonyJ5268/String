#include <cstdlib>
#include <iostream>

#include "string.h"


string::string() {
    this->len_ = 11;
    this->string_value_ = new char[this->len_];
    char cont[this->len_] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    for ( int i = 0; i < this->len_; i++ ){
      this->string_value_[i] = cont[i];
    }
}

char string::getChar(const int i){
  return this->string_value_[i];
}

int string::length(){
  return this->len_;
}

string::string(const char* c_string){
  this->len_ = 0;

  // get the length
  while (c_string[this->len_+1]!='0'||c_string[this->len_]!='\\'){
    this->len_++;
    if (this->len_>this->max_length_){
      std::cout << "string too long" << std::endl;
      this->len_ =-1;
      break;
    }
  }

  // make the array
  this->string_value_ = new char[this->len_];
  for ( int i = 0; i < this->len_; i++ ){
    this->string_value_[i] = c_string[i];
  }
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
