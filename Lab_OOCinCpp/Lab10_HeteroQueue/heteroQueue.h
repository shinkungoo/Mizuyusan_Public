//
// Created by Shizumu on 2022/6/2.
//

#ifndef HETROQUEUE_HETEROQUEUE_H
#define HETROQUEUE_HETEROQUEUE_H
#include <string>
#include <cstdint>
#include <iostream>
class Base{
public:
    virtual void print() const = 0;
};

class INT : public Base{
private:
    int _v_;
public:
    explicit INT(int v = 0);
    ~INT();
    INT(const INT & i);
    INT(INT && i) noexcept;
    int item() const;
    void print() const override;
};

class CHAR : public Base{
private:
    char _v_;
public:
    explicit CHAR(char v = '\0');
    ~CHAR();
    CHAR(const CHAR & c);
    CHAR(CHAR && i) noexcept;
    char item() const;
    void print() const override;
};

class PhoneNumber : public Base{
public:
    using string = std::string;
    using istream = std::istream;
private:
    string _name_;
    int64_t _number_;
public:
    PhoneNumber();
    PhoneNumber(const string & name, int64_t number);
    ~PhoneNumber();
    PhoneNumber(const PhoneNumber & pn);
    PhoneNumber(PhoneNumber && pn) noexcept;
    void reset(const string& new_name, int64_t new_number);
    string name() const;
    int64_t number() const;
    void print() const override;
    friend istream& operator>>(istream & is, PhoneNumber & pn);
};

class Hqueue{
private:
    Base **q;
    int _max_size_;
    int _rear_;
    int _front_;
public:
    struct bad_op{
    public:
        int type;
        explicit bad_op(int t){ type = t;}
    };
    int max_size() const;
    int size() const;
    explicit Hqueue(int size = 100);
    ~Hqueue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(Base * b);
    void dequeue();
};

#endif //HETROQUEUE_HETEROQUEUE_H
