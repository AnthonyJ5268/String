#ifndef STRING_H
#define STRING_H

class string {
  public:
    string();
    char getChar(int i); 

// Student A
    string(const string& other); // copy constructor
    char* c_str() const;
    int size() const;
    void clear();
    string& operator=(char c);
    friend string operator+(const string& s, const char* c); // non-member function

//Student B
    //string(string c_string);
    //int length();
    //int max_size();
    //void resize(int size_t, char char_);
    //operator=(const string&);
    //operator+(const string&, char char_);

//Student C

  protected:
    char* string_value_;
    int len_;

};


#endif
