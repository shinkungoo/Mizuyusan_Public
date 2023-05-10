//
// Created by Shizumu on 2022/6/2.
//
#include "heteroQueue.h"
#include <iostream>
#include <iomanip>
#include <string>

/**********************************************/
INT::INT(int v) {
    _v_ = v;
}

INT::~INT() = default;
INT::INT(const INT &i) = default;
INT::INT(INT &&i) noexcept  = default;

int
INT::item() const {
    return _v_;
}

void
INT::print() const{
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "INT:" << item();
}
/**********************************************/
CHAR::CHAR(char v) {
    _v_ = v;
}

CHAR::~CHAR() = default;
CHAR::CHAR(const CHAR &c) = default;
CHAR::CHAR(CHAR &&i) noexcept = default;

char
CHAR::item() const {
    return _v_;
}

void
CHAR::print() const {
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "CHAR:" << item();
}
/**********************************************/
PhoneNumber::PhoneNumber() {
    _name_ = "default";
    _number_ = 0;
}

PhoneNumber::PhoneNumber(const string &name, int64_t number) {
    _name_ = name;
    _number_ = number;
}

PhoneNumber::~PhoneNumber() = default;
PhoneNumber::PhoneNumber(const PhoneNumber &pn) = default;
PhoneNumber::PhoneNumber(PhoneNumber &&pn) noexcept = default;

void
PhoneNumber::reset(const string &new_name, int64_t new_number) {
    _name_ = new_name;
    _number_ = new_number;
}

std::string
PhoneNumber::name() const{
    return _name_;
}

int64_t
PhoneNumber::number() const{
    return _number_;
}

void
PhoneNumber::print() const{
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "PhoneNumber:"
              << "(" << _name_ << ", " << _number_ << ")";
}

std::istream &
operator>>(std::istream & is, PhoneNumber & pn){
    std::string in_name;
    int64_t in_number;
    is >> in_name >> in_number;
    pn.reset(in_name, in_number);

    return is;
}
/**********************************************/
int
Hqueue::max_size() const{
    return _max_size_;
}

int
Hqueue::size() const{
    int ret = _rear_ - _front_;
    if(ret < 0){
        ret += _max_size_;
    }

    return ret;
}

Hqueue::Hqueue(int size) {
    q = new Base*[size];
    _max_size_ = size;
    _front_ = _rear_ = 0;
}

Hqueue::~Hqueue() {
    delete [] q;
}

bool
Hqueue::isEmpty() const{
    return _rear_ == _front_;
}

bool
Hqueue::isFull() const {
    return (_rear_ + 1) % _max_size_ == _front_ % _max_size_;
}

void
Hqueue::enqueue(Base *b) {
    if(isFull()){
        throw bad_op(1);
    }
    _rear_ = (_rear_ + 1) % _max_size_;
    q[_rear_] = b;
}

void
Hqueue::dequeue() {
    if(isEmpty()) {
        throw bad_op(0);
    }
    _front_ = (_front_ + 1) % _max_size_;
    auto temp = q[_front_];
    temp->print();
    std::cout << std::endl;
    delete temp;
}
