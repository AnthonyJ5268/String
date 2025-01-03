#include <cstdlib>
#include <iostream>
#include "string.h"

void print(string s);
void test_hello_world();

//Student A
void  test_copy_constructorA();
void  test_c_str();
void  test_size();
void  test_clear();
void  test_string_equal_char();
void  test_string_plus_charstar();

//Student B
void test_constr_cstring();
void test_resize();
void test_operatorsB();

//Student C
void test_1(string s);
void test_default_constructor();
void test_constructor_with_char_ptr();
void test_copy_constructor();
void test_capacity();
void test_empty(); 
void test_reserve();
void test_operator_equal();
void test_operator_plus();

int main() {

//Student A
  std::cout<< ">>> Student A" <<std::endl;
  test_copy_constructorA();
  test_c_str();
  test_size();
  test_clear();
  test_string_equal_char();
  test_string_plus_charstar();
  std::cout<<std::endl;

//Student B
  std::cout<< ">>> Student B" <<std::endl;
  test_constr_cstring();
  test_resize();
  std::cout<<std::endl;
  test_operatorsB();
  std::cout<<std::endl;

//Student C
  std::cout<< ">>> Student C" <<std::endl;
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

void print(string s){
  for (size_t i=0; i < s.length() ; i++) {
    std::cout << s.getChar(i);
  }
  std::cout << std::endl;
}


// Student A

void test_copy_constructorA(){
  string a("Hey!");
  std::cout << "String a: " << std::endl;
  print(a);

  string b = a; // copy constructor
  std::cout << "String b copied from string a: " << std::endl;
  print(b);
}

void test_c_str(){
  string c;
  char* c_string = c.c_str(); // c_str() member function
  std::cout << "String c to c_str: " << c_string << std::endl;
  delete[] c_string;
}

void test_size(){
  string d;
  std::cout << "String d: " << std::endl;
  print(d);
  std::cout << "The size of string d is " << d.size() << std::endl;
}

void test_clear(){
  string e;
  std::cout << "String e: " << std::endl;
  print(e);
  e.clear();
  std::cout << "Strings cleared." << std::endl;
  std::cout << "String e cleared: " << std::endl;
  print(e);
}

void test_string_equal_char(){
  string f;
  f = 'F';
  std::cout << "Usage of = operator (string=char): " << std::endl;
  std::cout << "f = ";
  print(f);
}

void test_string_plus_charstar(){
  string g;
  g = g + " How are you?";
  std::cout << "Usage of + operator: " << std::endl;
  std::cout << "(Hello world) + (How are you?) = ";
  print(g);
}


// Student B

void test_constr_cstring(){
  char cs[] = "this is a c-string\0";
  std::cout << "char[] : " << cs << std::endl;
  string from_cs(cs);
  std::cout << "string : ";
  print(from_cs);
}

void test_resize(){
  string resize_me("this is a c-string\0");
  std::cout << "string : ";
  std::cout << "initial length : " << resize_me.length() << std::endl;
  resize_me.resize(10);
  std::cout << "-> Resized" << std::endl;
  std::cout << "string : ";
  print(resize_me);
  std::cout << "length : " << resize_me.length() << std::endl;
  std::cout << "max length : " << resize_me.max_size() << std::endl;
}

void test_operatorsB(){
  std::cout << "s1 : ";
  string s1("Here's a c-string\0");
  print(s1);

  string s2("Here's another\0");
  std::cout << "s2 : ";
  print(s2);

  s2=s1;
  std::cout << "s2=s1 : ";
  print(s2);

  string s3 = s2 + '!';
  std::cout << "s3=s2+! : ";
  print(s3);
}


// Student C

void test_1(string a){
  size_t a_length = a.length();
  if (a_length > 0) {
    print(a);
  }
}

void test_default_constructor(){
  string a;
  std::cout << "Default Constructor: ";
  print(a);
}

void test_constructor_with_char_ptr() {
  string a("Hello World");
  std::cout << "Constructor with char*: ";
  print(a);
}

void test_copy_constructor() {
  string a("Copy Hello");
  string b(a);
  std::cout << "Copy Constructor: ";
  print(b);
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
}

void test_operator_equal() {
  char cont[7] = {'Y', 'o', 'u', 'p', 'i', '!','\0'};
  string b;
  b = cont;
  std::cout << "Operator= : ";
  print(b);
}

void test_operator_plus() {
  string c("Hello");
  string d(" World");
  string e = c + d;
  std::cout << "Operator+: ";
  print(e);
}
