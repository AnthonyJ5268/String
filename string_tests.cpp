#include <cstdlib>
#include <iostream>
//#include <cstring>

#include "string.h"


void print(string s);

void test_hello_world();
void test_constr_cstring();
void test_resize();
void test_operatorsB();


int main(){
  test_hello_world();
  std::cout<<std::endl;
  test_constr_cstring();
  std::cout<<std::endl;
  test_resize();
  std::cout<<std::endl;
  test_operatorsB();
}

void print(string s){
  for (size_t i=0; i < s.length() ; i++) {
    std::cout << s.getChar(i);
  }
  std::cout << std::endl;
}

void test_hello_world(){
  string hw;
  print(hw);
}

void test_constr_cstring(){
  char c[] = "this is a c-string\\0";
  std::cout << c << std::endl;
  string from_cs(c);
  print(from_cs);
  std::cout << from_cs.length() << std::endl;
  std::cout << from_cs.max_size() << std::endl;
}

void test_resize(){
  string resize_me("this is a c-string\\0");
  resize_me.resize(10);
  std::cout << "resized :" << std::endl;
  print(resize_me);
}

void test_operatorsB(){
  string s1("Here's a c-string\\0");
  string s2("Here's another\\0");
  print(s1);
  print(s2);
  s2=s1;
  print(s2);
  string s3 = s2 + '!';
  print(s3);
}