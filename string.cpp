#include <cstdlib>
#include <iostream>
#include <cassert>
#include "string.h"

//Default constructor
string::string() {
    len_ = 11;
    capacity_ = 12;
    string_value_ = new char[capacity_];
    char cont[capacity_] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'};
    for ( size_t i = 0; i < capacity_; i++ ){
      string_value_[i] = cont[i];
    }
}

char string::getChar(const size_t i) const{
  return string_value_[i];
}

//Student A

//copy constructor
string::string(const string& other) { // deep copy
    len_ = other.len_;
    capacity_ = other.capacity_;
    string_value_ = new char[capacity_];
    for (size_t i = 0; i < len_; i++) {
        string_value_[i] = other.string_value_[i];
    }
    string_value_[len_] = '\0';
}

// c_str()
char* string::c_str() const{
    char* cstr = new char[len_ + 1];
    for ( size_t i = 0; i < len_; i++) {
        cstr[i] = string_value_[i];
    }
    cstr[len_] = '\0';
    return cstr;
}

// size()
size_t string::size() const{
    size_t res = 0;
    while (res <= len_ && string_value_[res] != '\0') {
        res++;
    }
    return res;
}

// clear()
void string::clear() {
    delete[] string_value_; // release old memory
    string_value_ = new char[1];
    string_value_[0] = '\0';
    len_ = 0;
    capacity_ = 1;
}

// operator=(char) 
string& string::operator=(char c) {
    delete[] this->string_value_;
    len_ = 1;
    capacity_ = 2;
    string_value_ = new char[2];
    string_value_[0] = c;
    string_value_[1] = '\0';
    return *this;
}


// operator+(const string&, const char*)
string operator+(const string& s, const char* c) {
    size_t s_size = s.size();
    size_t c_size = 0;
    while (c[c_size] != '\0') {
        c_size++;
    }
    string res(s);
    delete[] res.string_value_;
    res.len_ = s_size + c_size;
    res.string_value_ = new char[res.len_ + 1];
    for ( size_t i = 0; i < s_size; i++) {
        res.string_value_[i] = s.string_value_[i];
    }
    for ( size_t i = 0; i < c_size; i++) {
        res.string_value_[i + s_size] = c[i];
    }
    res.string_value_[res.len_] = '\0';
    return res;
}


//Student B

// Constructor from c string
string::string(const char* c_string){
  len_ = 0;

  // get the length
  while (c_string[len_]!='\0'){
    len_++;
    if (len_>max_length_){
      std::cout << "string too long" << std::endl;
      len_ =-1;
      break;
    }
  }
  capacity_ = len_+1;

  // make the array
  string_value_ = new char[capacity_];
  for ( size_t i = 0; i < len_; i++ ){
    string_value_[i] = c_string[i];
  }
  string_value_[len_] = '\0';
}

// length()
size_t string::length() const{
  return len_;
}

// max_size()
size_t string::max_size() const{
  return max_length_;
}

// resize()
void string::resize(size_t new_size_, char char_){
  assert(new_size_ <= max_length_ && "new size should be between 0 and 100");

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
  capacity_ = len_+1;
  string_value_[len_] = '\0';

}

// operator=(condt string&)
string string::operator=(const string& s_){
  this->resize(s_.length());
  
  for ( size_t i = 0; i < len_; i++ ){
    string_value_[i] = s_.getChar(i);
  }
  string_value_[len_] = '\0';
  return *this;
}

// operator+(const string&, char)
string operator+(const string& s_, char char_) {
    string s_res_(s_);
    s_res_.resize(s_.len_ + 1);
    s_res_.string_value_[s_.len_] = char_;
    return s_res_;
}

//Student C

/*
destructor attention !!! A revoir a la fin du projet pour tout retirer / remettre à 0 !
String destructor
Destroys the string object.
This deallocates all the storage capacity allocated by the string using its allocator.
*/
string::~string() noexcept {
  if (this->string_value_ != nullptr) {
    delete[] this->string_value_;
    this->string_value_ = nullptr;
    this->len_ = 0;
    this->capacity_ = 0;
  }
}

/*
capacity : Return size of allocated storage
Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
This capacity is not necessarily equal to the string length. It can be equal or greater, with the extra space allowing the object to optimize its operations when new characters are added to the string.
Notice that this capacity does not suppose a limit on the length of the string. When this capacity is exhausted and more is needed, it is automatically expanded by the object (reallocating it storage space). The theoretical limit on the length of a string is given by member max_size.
The capacity of a string can be altered any time the object is modified, even if this modification implies a reduction in size or if the capacity has not been exhausted (this is in contrast with the guarantees given to capacity in vector containers).
*/
size_t string::capacity() const noexcept{
  return this->capacity_;
}

/*
empty : Test if string is empty
Returns whether the string is empty (i.e. whether its length is 0).
This function does not modify the value of the string in any way. To clear the content of a string, see string::clear.
*/
bool string::empty() const noexcept{
  return this->len_ == 0;
}

/*
reserve : Request a change in capacity
Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters (or greater).
In all other cases, it is taken as a non-binding request to shrink the string capacity: the container implementation is free to optimize otherwise and leave the string with a capacity greater than n.
This function has no effect on the string length and cannot alter its content.
*/
void string::reserve(size_t n) noexcept {
  assert(n >= 0 && "n should not be negative");
  if (n > this->max_length_){
    n = this->max_length_;
  }
  if (n > this->capacity_){
    char* new_string = new char[n];
    for (size_t i = 0; i < this->len_; i++){
      new_string[i] = this->string_value_[i];
    }
    delete[] this->string_value_;
    this->string_value_ = new_string;
    this->capacity_ = n;
  }
}


/*
operator=(const char* s) : String assignment
Assigns a new value to the string, replacing its current contents.
*/
string& string::operator=(const char* s) noexcept {

  if (this->string_value_ == s){
        return *this;
    }

  if (s == nullptr){
      delete[] string_value_;
      this->len_ = 0;
      this->capacity_ = 1;
      this->string_value_ = new char[capacity_];
      this->string_value_[0] = '\0';
      return *this;
  }

  else{

    size_t taille_s = 0;
    while (s[taille_s] != '\0'){
    ++taille_s;
    }

    if (taille_s > this->max_length_) {
    taille_s = this->max_length_;
    }

    delete[] this->string_value_;
    this->len_ = taille_s;
    this->capacity_ = len_ + 1;  // +1 pour le caractere nulle , et à voir si on souaite une capacité plus grande
    this->string_value_ = new char[this->capacity_];
    for (size_t i = 0; i < this->len_; ++i) {
        this->string_value_[i] = s[i];
    }
    this->string_value_[this->len_] = '\0';
    return *this;
  }

}

/*
string operator+(const string& s1, const string& s2) {
Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
*/
string operator+(const string& lhs, const string& rhs) noexcept {
    string concat_string(lhs);
    size_t concat_size = lhs.len_ + rhs.len_;

    if (concat_size + 1 > concat_string.capacity_) {
        concat_string.reserve(concat_size + 1);
    }

    for (size_t i = 0; i < rhs.len_; ++i) {
        concat_string.string_value_[lhs.len_ + i] = rhs.string_value_[i];
    }

    concat_string.string_value_[concat_size] = '\0';
    concat_string.len_ = concat_size;
    return concat_string;
}
