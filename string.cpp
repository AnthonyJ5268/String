#include <cstdlib>
#include <iostream>

#include "string.h"


string::string() {
    len_ = 11;
    string_value_ = new char[len_];
    char cont[len_] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    for ( size_t i = 0; i < len_; i++ ){
      string_value_[i] = cont[i];
    }
}

//Student A



//Student B
string::string(const char* c_string){
  len_ = 0;

  // get the length
  while (c_string[len_+1]!='0'||c_string[len_]!='\\'){
    len_++;
    if (len_>max_length_){
      std::cout << "string too long or not a c-string" << std::endl;
      len_ =-1;
      break;
    }
  }

  // make the array
  string_value_ = new char[len_];
  for ( size_t i = 0; i < len_; i++ ){
    string_value_[i] = c_string[i];
  }
}

char string::getChar(const size_t i) const{
  return string_value_[i];
}

size_t string::length() const{
  return len_;
}

size_t string::max_size() const{
  return max_length_;
}

void string::resize(size_t new_size_, char char_){

  char cont[new_size_];

  if (len_ < new_size_){
    for ( size_t i = 0; i < len_; i++ ){
      cont[i] = string_value_[i];
    }
    for ( size_t i = len_; i < new_size_; i++ ){
      cont[i] = char_;
    }
  }

  if (len_ > new_size_){
    for ( size_t i = 0; i < new_size_; i++ ){
      cont[i] = string_value_[i];
    }
  }

  delete[] string_value_;
  string_value_ = new char[new_size_];

  for (size_t i = 0; i < new_size_; i++){
    string_value_[i] = cont[i];
  }
  len_ = new_size_;
}


string string::operator=(const string& s_){
  this->resize(s_.length());
  
  for ( size_t i = 0; i < len_; i++ ){
    string_value_[i] = s_.getChar(i);
  }
  return *this;
}


string operator+(const string& s_, char char_) {
    string s_res_(s_);
    s_res_.resize(s_.len_ + 1);
    s_res_.string_value_[s_.len_] = char_;
    return s_res_;
}

//Student C
