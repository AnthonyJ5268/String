#include <cstdlib>
#include <iostream>

#include "string.h"


int main(){
  string a = string();
  for (int i ; i < 11 ; i++) {
    std::cout << a.getChar(i);
  }
  std::cout << std::endl;
}
