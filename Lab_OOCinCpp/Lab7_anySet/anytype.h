/**
 * structure design
 */
#ifndef ANYSET_ANYTYPE_H
#define ANYSET_ANYTYPE_H
#include <iostream>
struct TelephoneNumber{
    // members
    char *name;
    int number;
    // constructors and destructors
    TelephoneNumber();
    explicit TelephoneNumber(int n);
    TelephoneNumber(const char *s, int n);
    TelephoneNumber(const TelephoneNumber &);
    ~TelephoneNumber();
    // overload operators
    bool operator<(const TelephoneNumber & t) const;
    bool operator>(const TelephoneNumber & t) const;
    bool operator==(const TelephoneNumber & t) const;
    bool operator!=(const TelephoneNumber & t) const;
    TelephoneNumber & operator=(const TelephoneNumber & t);
    TelephoneNumber & operator=(const int & n);
    friend std::ostream & operator<<(std::ostream & os, const TelephoneNumber & t);
};
#endif //ANYSET_ANYTYPE_H
