#include "string.h"

//Constructors
string::string() {
    len_ = 11;
    string_value_ = new char[12];
    char cont[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'};
    for ( int i = 0; i < 11; i++ ){
        string_value_[i] = cont[i];
    }
}

/*string::string() {
    this->len_ = 100;
    this->string_value_ = new char[len_];
}*/

char string::getChar(int i){
    return string_value_[i];
}

//Student A

//copy constructor
string::string(const string& other) { // deep copy
    len_ = other.len_;
    string_value_ = new char[other.len_];
    for (int i = 0; i < len_; i++) {
        string_value_[i] = other.string_value_[i];
    }
}

// c_str()
char* string::c_str() const{
    char* cstr = new char[len_ + 1];
    for ( int i = 0; i < len_; i++) {
        cstr[i] = string_value_[i];
    }
    cstr[len_] = '\0';
    return cstr;
}

// size()
int string::size() const{
    int res = 0;
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
}

// operator=(char) 
string& string::operator=(char c) {
    delete[] this->string_value_;
    len_ = 1;
    string_value_ = new char[2];
    string_value_[0] = c;
    string_value_[1] = '\0';
    return *this;
}


// operator+(const string&, const char*)
string operator+(const string& s, const char* c) {
    int s_size = s.size();
    int c_size = 0;
    while (c[c_size] != '\0') {
        c_size++;
    }
    string res;
    delete[] res.string_value_;
    res.len_ = s_size + c_size;
    res.string_value_ = new char[res.len_ + 1];
    for ( int i = 0; i < s_size; i++) {
        res.string_value_[i] = s.string_value_[i];
    }
    for ( int i = 0; i < c_size; i++) {
        res.string_value_[i + s_size] = c[i];
    }
    res.string_value_[res.len_] = '\0';
    return res;
}



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
