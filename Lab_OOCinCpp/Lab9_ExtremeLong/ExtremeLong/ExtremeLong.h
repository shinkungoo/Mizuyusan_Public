/*****************************************************************
 * Created by Shizumu on 2022-05-11
 * This declaration imitates that in Java(BigInteger class)
 * It's too hard to implement them...
 * But I make it!!!!!
 */
#ifndef EXTREMELONG_EXTREMELONG_H
#define EXTREMELONG_EXTREMELONG_H
#include <deque>
#include <string>
#include <iostream>
#include <cstdint>
struct algo{
    using integer       =   int32_t;
    using long_integer  =   int64_t;
    using array         =   std::deque<integer>;
    using string        =   std::string;

    const static long_integer LONG_MASK = 0xffffffffLL;
    const static integer WORD_MASK = 0x00000001;
    struct bad_IntegerAlgorithm{
        string _what_;
        explicit bad_IntegerAlgorithm(string what){
            _what_ = std::move(what);
        }
        string what() const{
            return _what_;
        }
    };
    integer numberOfLeadingZeros(integer number) const;
    integer bitLengthInInt(integer number);
    integer bitCount(integer number);
    integer stringToInt(string stringNumber);
    void destructiveMulAdd(array & x, integer y, integer z);
    array add(const array& x, const array& y) const;
    array subtract(const array& x, const array& y) const;
    array multiplyOneWord(const array & x, integer number) const;
    array multiplyByArray(const array &x, const array &y) const;
};

class ExtremeLong{
public:
    using integer       =   int32_t;
    using long_integer  =   int64_t;
    using array         =   std::deque<integer>;
    using string        =   std::string;
private:
    const static integer digitPerInt = 9;
    const static integer offsetOfDigitPerInt = 0x3b9aca00;  // this is 1000000000;
    integer     _signum_;               // -1 for negative, 0 for zero, or +1 for positive.
    array       _mag_;                  // The magnitude of this BigInteger, in big-endian order.
    integer     _bitLength_;
    algo        func;
    /// helper function
    integer bitLength();
    ExtremeLong negate() const;
    integer compareMagnitude(const ExtremeLong & bigint) const;
    std::pair<integer/*remainder*/, ExtremeLong/*quotient*/> divideOneWord(integer number) const;
public:
    /// exception
    struct bad_ExtremeLong{
        string _what_;
        explicit bad_ExtremeLong(string what){
            _what_ = std::move(what);
        }
        string what() const{
            return _what_;
        }
    };

    /// other function;
    integer digits() const;
    string toString() const;
    /// constructors
    explicit ExtremeLong(integer number = 0);
    explicit ExtremeLong(long_integer number);
    explicit ExtremeLong(const string& numberString);
    /// copy constructor
    ExtremeLong(const ExtremeLong & bigint);
    /// destructor
    ~ExtremeLong();
    /// move constructor
    ExtremeLong(ExtremeLong && bigint);
    /// assignment operator overloading
    ExtremeLong& operator=(const ExtremeLong & bigint);
    ExtremeLong& operator=(ExtremeLong && bigint);
    /// operator overload
    ExtremeLong operator+(const ExtremeLong & bigint) const;
    ExtremeLong operator+(const string & numberString) const;
    ExtremeLong operator+(long_integer number) const;
    ExtremeLong operator-(const ExtremeLong & bigint) const;
    ExtremeLong operator-(long_integer number) const;
    ExtremeLong operator-(const string & numberString) const;
    ExtremeLong operator-() const;
    ExtremeLong operator*(const ExtremeLong & bigint) const;
    ExtremeLong operator*(integer number) const;
    ExtremeLong operator*(const string & numberString) const;
    ExtremeLong operator/(integer number) const;
    integer operator%(integer number) const;
    ExtremeLong operator<<(long_integer number) const;
    ExtremeLong operator>>(long_integer number) const;

    ExtremeLong& operator+=(const ExtremeLong & bigint);
    ExtremeLong& operator+=(long_integer number);
    ExtremeLong& operator+=(const string & numberString);
    ExtremeLong& operator-=(const ExtremeLong & bigint);
    ExtremeLong& operator-=(long_integer number);
    ExtremeLong& operator-=(const string & numberString);
    ExtremeLong& operator*=(const ExtremeLong & bigint);
    ExtremeLong& operator*=(long_integer number);
    ExtremeLong& operator*=(const string & numberString);
    ExtremeLong& operator/=(integer number);
    /// exponent computing operator
    ExtremeLong operator^(long_integer number) const;
    /// cin and cout overload
    friend std::ostream & operator<<(std::ostream & os, const ExtremeLong & bigint);
    friend std::istream & operator>>(std::istream & is, ExtremeLong & bigint);

    friend ExtremeLong operator+(long_integer number, const ExtremeLong & bigint);
    friend ExtremeLong operator-(long_integer number, const ExtremeLong & bigint);
    friend ExtremeLong operator*(long_integer number, const ExtremeLong & bigint);
};
/// literals overloading
ExtremeLong
operator"" xl(const char *literalNumber);

ExtremeLong
operator"" XL(const char *literalNumber);

#endif //EXTREMELONG_EXTREMELONG_H
