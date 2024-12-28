#ifndef STRING_H
#define STRING_H
// #include <cstddef>  to see if we are allowed to use this library for size_t

class string {
  public:
    string();
    string(const char* s);
    string(const string& other);

    char getChar(int i); 


    //string(string c_string);
    int length() const;
    //int max_size();
    //void resize(int size_t, char char_);
    //operator=(const string&);
    //operator+(const string&, char char_);


    ~string() noexcept;
    int capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(int n) noexcept;
    string& operator=(const char *s) noexcept;
    friend string operator+(const string& lhs, const string& rhs) noexcept;

protected:
    char* string_value_;
    int len_;
    int capacity_;

private:
    int max_length_ = 100;

};


#endif
