#ifndef STRING_H
#define STRING_H

#include <cstdlib>

class string {
  public:
    string();
    char getChar(size_t i) const;
// Student A
    string(const string& other); // copy constructor
    char* c_str() const;
    int size() const;
    void clear();
    string& operator=(char c);
    friend string operator+(const string& s, const char* c); // non-member function

//Student B
    string(const char* c_string);
    size_t length() const;
    size_t max_size() const;
    void resize(size_t new_size_, char char_ = ' ');
    string operator=(const string& s_);
    friend string operator+(const string& s_, char char_);

//Student C
    ~string() noexcept;
    size_t capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_t n) noexcept;
    string& operator=(const char *s) noexcept;
    friend string operator+(const string& lhs, const string& rhs) noexcept;

  protected:
    char* string_value_;
    size_t len_;
    size_t max_length_ = 100;
    size_t capacity_;

};


#endif
