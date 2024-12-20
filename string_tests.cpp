#include <cstdlib>
#include <iostream>
//#include <cstring>

#include "string.h"

void test_hello_world();
void test_constr_cstring();
void print(string s);

int main(){
  test_hello_world();
  //std::cout << "0" << std::endl;
  test_constr_cstring();

}

void test_hello_world(){
  string a;
  print(a);
}

void print(string s){
  for (int i=0; i < s.length() ; i++) {
    std::cout << s.getChar(i);
  }
  std::cout << std::endl;
}

void test_constr_cstring(){
  char c[] = "this is a c-string\\0";
  std::cout << c << std::endl;

  string b(c);
  print(b);
  /*
  for (int i ; i < b.length() ; i++) {
    std::cout << b.getChar(i);
  }
  std::cout << std::endl;
*/
}
