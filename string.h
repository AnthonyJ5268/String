#ifndef STRING_H
#define STRING_H

#include <cstdlib>

class string {
  public:
    string();
    char getChar(size_t i) const;
// Student A

//Student B
    string(const char* c_string);
    size_t length() const;
    size_t max_size() const;
    void resize(size_t new_size_, char char_ = ' ');
    string operator=(const string& s_);
    friend string operator+(const string& s_, char char_);

//Student C

  protected:
    char* string_value_;
    size_t len_;
    size_t max_length_ = 100;

};


#endif
