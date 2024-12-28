// #include <cstddef>  to see if we are allowed to use this library for size_t
#include <iostream>
#include "string.h"

void test_1(string a){
  int a_length = a.length();
  if (a_length > 0) {
    for (int i = 0; i < a_length; i++)
    {
      std::cout << a.getChar(i);
    }
  }
  std::cout << std::endl;
}

void test_default_constructor() {
  string a;
  std::cout << "Default Constructor: ";
  int a_length = a.length();
  for (int i = 0; i < a_length; i++) {
    std::cout << a.getChar(i);
  }
  std::cout << std::endl;
}

void test_constructor_with_char_ptr() {
  string a("Hello World");
  std::cout << "Constructor with char*: ";
  int a_length = a.length();
  for (int i = 0; i < a_length; i++) {
    std::cout << a.getChar(i);
  }
  std::cout << std::endl;
}

void test_copy_constructor() {
  string a("Copy Hello");
  string b(a);
  std::cout << "Copy Constructor: ";
  int a_length = a.length();
  for (int i = 0; i < a_length; i++) {
    std::cout << b.getChar(i);
  }
  std::cout << std::endl;
}

void test_capacity() {
  string a("Hello");
  std::cout << "Capacity: " << a.capacity() << std::endl;
}

void test_empty() {
  string a;
  std::cout << "Empty: " << a.empty() << std::endl;
  string b("Hello");
  std::cout << "Empty: " << b.empty() << std::endl;
  string c("");
  std::cout << "Empty: " << c.empty() << std::endl;
}

void test_reserve() {
  string a("Hello");
  a.reserve(20);
  std::cout << "Reserve: " << a.capacity() << std::endl;
  string b("Hello");
  b.reserve(4);
  std::cout << "Reserve: " << b.capacity() << std::endl;
  /*
  string c("Hello");
  c.reserve(-4);
  std::cout << "Reserve: " << c.capacity() << std::endl;
  */
}

void test_operator_equal() {
  char cont[7] = {'Y', 'o', 'u', 'p', 'i', '!','\0'};
  string b;
  b = cont;
  std::cout << "Operator= : ";
  int b_length = b.length();
  for (int i = 0; i < b_length; i++) {
    std::cout << b.getChar(i);
  }
  std::cout << std::endl;
}

void test_operator_plus() {
  string c("Hello");
  string d(" World");
  string e = c + d;
  std::cout << "Operator+: ";
  int e_length = e.length();
  for (int i = 0; i < e_length; i++) {
    std::cout << e.getChar(i);
  }
  std::cout << std::endl;
}

int main() {
  
  test_1(string()); //OK
  test_default_constructor(); //OK
  test_constructor_with_char_ptr(); //OK
  test_copy_constructor(); //OK
  test_capacity(); //OK
  test_empty(); //OK
  test_reserve(); //OK
  test_operator_equal(); //OK
  test_operator_plus(); //OK

  return EXIT_SUCCESS;
}
