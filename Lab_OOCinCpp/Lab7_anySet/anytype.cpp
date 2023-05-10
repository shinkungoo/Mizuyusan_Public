/**
 * structure implementation
 */
#include "anytype.h"
#include <cstring>
#include <iostream>

using std::strlen;
using std::strcpy;
using std::strcmp;

TelephoneNumber::TelephoneNumber() {
    name = new char[strlen("default") + 1];
    strcpy(name, "default");
    number = 0;
}

TelephoneNumber::TelephoneNumber(int n) {
    name = new char[strlen("default") + 1];
    strcpy(name, "default");
    number = n;
}

TelephoneNumber::TelephoneNumber(const char *s, int n) {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
    number = n;
}

TelephoneNumber::TelephoneNumber(const TelephoneNumber &t) {
    name = new char[strlen(t.name) + 1];
    strcpy(name, t.name);
    number = t.number;
}

TelephoneNumber::~TelephoneNumber() {
    delete[] name;
}

bool TelephoneNumber::operator<(const TelephoneNumber &t) const {
    int c;
    if((c = strcmp(name, t.name)) != 0){
        return c < 0;
    }else{
        return number < t.number;
    }
}

bool TelephoneNumber::operator>(const TelephoneNumber &t) const {
    int c;
    if((c = strcmp(name, t.name)) != 0){
        return c > 0    ;
    }else{
        return number > t.number;
    }
}

bool TelephoneNumber::operator==(const TelephoneNumber &t) const {
    return strcmp(name, t.name) == 0 && number == t.number;
}

bool TelephoneNumber::operator!=(const TelephoneNumber &t) const {
    return strcmp(name, t.name) != 0 || number != t.number;
}

TelephoneNumber &TelephoneNumber::operator=(const TelephoneNumber &t) {
    if(this == &t){
        return *this;
    }
    delete [] name;
    name = new char[strlen(t.name) + 1];
    strcpy(name, t.name);
    number = t.number;

    return *this;
}

TelephoneNumber &TelephoneNumber::operator=(const int &n) {
    delete [] name;
    name = new char[strlen("default") + 1];
    strcpy(name, "default");
    number = n;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const TelephoneNumber &t) {
    os << "(" << t.name << "," << t.number << ")";

    return os;
}

