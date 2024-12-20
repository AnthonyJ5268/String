#ifndef STRING_H
#define STRING_H

class string {
  public:
    string();
    char getChar(int i);
// Student A

//Student B
    string(const char* c_string);
    int length();
    //int max_size();
    //void resize(int size_t, char char_);
    //operator=(const string&);
    //operator+(const string&, char char_);

//Student C

  protected:
    char* string_value_;
    int len_;
    int max_length_ = 100;

};


#endif
