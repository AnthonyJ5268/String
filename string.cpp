#include "string.h"
#include <cassert>
// #include <cstddef>  to see if we are allowed to use this library for size_t


string::string(){
    this->string_value_ = new char[12];
    this->len_ = 11;
    this->capacity_ = 12;
    char cont[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'};
    for ( int i = 0; i < 12; i++ ){
      this->string_value_[i] = cont[i];
    }
}

string::string(const char* s) {
    int taille_s = 0;
    while (s[taille_s] != '\0') {
        ++taille_s;
    }
    if (taille_s > this->max_length_) {
    taille_s = this->max_length_;
    }
    this->len_ = taille_s;
    this->capacity_ = this->len_ + 1;  // +1 pour le caractere nulle
    this->string_value_ = new char[this->capacity_];
    for (int i = 0; i < this->len_; ++i) {
        this->string_value_[i] = s[i];
    }
    this->string_value_[this->len_] = '\0';
}

string::string(const string& other) {
    this->len_ = other.len_;
    this->capacity_ = other.capacity_;
    this->string_value_ = new char[this->capacity_];
    for (int i = 0; i < this->len_; ++i) {
        this->string_value_[i] = other.string_value_[i];
    }
    this->string_value_[this->len_] = '\0';
}

char string::getChar(int i){
  return this->string_value_[i];
}

int string::length() const {
    return this->len_;
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

/*
destrucor attention !!! A revoir a la fin du projet pour tout retirer / remettre à 0 !
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
int string::capacity() const noexcept{
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
void string::reserve(int n) noexcept {
  assert(n >= 0 && "n should not be negative");
  if (n > this->max_length_){
    n = this->max_length_;
  }
  if (n > this->capacity_){
    char* new_string = new char[n];
    for (int i = 0; i < this->len_; i++){
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

    int taille_s = 0;
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
    for (int i = 0; i < this->len_; ++i) {
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
    int concat_size = lhs.len_ + rhs.len_;

    if (concat_size + 1 > concat_string.capacity_) {
        concat_string.reserve(concat_size + 1);
    }

    for (int i = 0; i < rhs.len_; ++i) {
        concat_string.string_value_[lhs.len_ + i] = rhs.string_value_[i];
    }

    concat_string.string_value_[concat_size] = '\0';
    concat_string.len_ = concat_size;
    return concat_string;
}
