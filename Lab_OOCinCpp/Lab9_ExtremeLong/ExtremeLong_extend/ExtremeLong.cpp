/*****************************************************************
 * Created by Shizumu on 2022-05-11
 * This implementation imitates that in Java(BigInteger class)
 */
#include "ExtremeLong.h"
#include <cctype>
#include <cmath>
/****************************************************************/
inline int64_t max(int64_t a, int64_t b){ return a > b ? a : b ;}
/****************************************************************/
///ReturnNumber
template<typename T>
ReturnNumber<T>::ReturnNumber(T x) {
    _item_ = x;
}

template<typename T>
T
ReturnNumber<T>::item() const {
    return _item_;
}
/// UtilityNumber
template<typename T>
T
UtilityNumber<T>::item() const{
    return _item_;
}

template<typename T>
UtilityNumber<T>::UtilityNumber() {
    _item_ = static_cast<T>(0);
}

template<typename T>
UtilityNumber<T>::UtilityNumber(T x) {
    _item_ = x;
}

template<typename T>
ReturnNumber<T>
UtilityNumber<T>::operator*(){
    return ReturnNumber<T>{_item_};
}

template<typename T>
UtilityNumber<T>&
UtilityNumber<T>::operator=(const UtilityNumber<T> &uNumber) {
    if(this == &uNumber){
        return *this;
    }
    _item_ = uNumber.item();
    return *this;
}

template<typename T>
UtilityNumber<T>&
UtilityNumber<T>::operator=(const T &uNumber) {
    _item_ = uNumber;
    return *this;
}

template<typename t>
std::istream&
operator>>(std::istream &is, UtilityNumber<t> &x){
    t temp;
    is >> temp;
    x = temp;

    return is;
}

template<typename t>
std::ostream &
operator<<(std::ostream &os, const UtilityNumber<t> & x){
    os << x.item();
    return os;
}


template class ReturnNumber<long>;
template class UtilityNumber<long>;
template std::ostream &operator<<(std::ostream &os, const UtilityNumber<long> &s);
template std::istream &operator>>(std::istream &is, UtilityNumber<long> &s);
/****************************************************************/
/**adopted from integer.java**/
algo::integer
algo::numberOfLeadingZeros(integer number) const{
    uint32_t i = number;
    if (i <= 0)
        return i == 0 ? 32 : 0;
    int n = 31;
    if (i >= 1 << 16) { n -= 16; i >>= 16; }
    if (i >= 1 <<  8) { n -=  8; i >>=  8; }
    if (i >= 1 <<  4) { n -=  4; i >>=  4; }
    if (i >= 1 <<  2) { n -=  2; i >>=  2; }
    return n - (i >> 1);
}

algo::integer
algo::numberOfTrailingZeros(integer number) {
    uint32_t i = number;
    i = ~i & (i - 1);
    if (i <= 0) return i & 32;
    int n = 1;
    if (i > 1 << 16) { n += 16; i >>= 16; }
    if (i > 1 <<  8) { n +=  8; i >>=  8; }
    if (i > 1 <<  4) { n +=  4; i >>=  4; }
    if (i > 1 <<  2) { n +=  2; i >>=  2; }
    return n + (i >> 1);
}

algo::integer
algo::bitLengthInInt(integer number) {
    return 32 - numberOfLeadingZeros(number);
}

algo::integer
algo::bitCount(integer number) {
    uint32_t i = number;
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}

algo::integer
algo::stringToInt(std::string stringNumber) {
    if(stringNumber.empty()){
        throw bad_IntegerAlgorithm("Illegal string of number");
    }
    integer result = 0;
    for(int i = 0 ; i < stringNumber.size(); i ++){
        if(!std::isdigit(stringNumber[i])){
            throw bad_IntegerAlgorithm("Illegal character of number");
        }
        result = result * 10 + (stringNumber[i] - '0');
    }

    return result;
}

algo::string
algo::toBinaryString(const array &x) const {
    string ret;
    if(x.size() == 1 && x[0] == 0){
        ret = "0";
    }else{
        for(int i = x.size() - 1; i >= 1 ; i --){
            uint32_t temp = x[i];
            integer cnt = 32;
            while(cnt){
                if(temp & WORD_MASK){
                    ret = std::move("1" + ret);
                }else{
                    ret = std::move("0" + ret);
                }
                temp >>= 1;
                cnt --;
            }
        }
        uint32_t temp = x[0];
        while(temp){
            if(temp & WORD_MASK){
                ret = std::move("1" + ret);
            }else{
                ret = std::move("0" + ret);
            }
            temp >>= 1;
        }
    }

    return std::move(ret);
}

algo::array
algo::add(const array& x, const array& y) const{
    if(x.size() < y.size()){
        return std::move(add(y, x));
    }
    int xIndex = x.size(), yIndex = y.size();
    array ret;
    uint64_t sum = 0;
    if(yIndex == 1){
        sum = (x[--xIndex] & LONG_MASK) + (y[0] & LONG_MASK);
        ret.push_front(sum & LONG_MASK);
    }else{
        while(yIndex > 0){
            sum = (x[--xIndex] & LONG_MASK) + (y[--yIndex] & LONG_MASK) + (sum >> 32);
            ret.push_front(sum & LONG_MASK);
        }
    }
    // Copy remainder of longer number while carry propagation is required
    while(xIndex > 0){
        sum = (x[--xIndex] & LONG_MASK) + (sum >> 32);
        ret.push_front(sum & LONG_MASK);
    }
    sum >>= 32;
    if(sum > 0){
        ret.push_front(sum & LONG_MASK);
    }

    return std::move(ret);
}

algo::array
algo::subtract(const array & x, const array &y) const {
    int bigIndex = x.size(), littleIndex = y.size();
    array ret;
    uint64_t difference = 0;
    while(littleIndex > 0){
        difference = (x[--bigIndex] & LONG_MASK) - (y[--littleIndex] & LONG_MASK) + (difference >> 32);
        ret.push_front(difference & LONG_MASK);
    }
    while(bigIndex > 0){
        difference = (x[--bigIndex] & LONG_MASK) + (difference >> 32);
        ret.push_front(difference & LONG_MASK);
    }
    if(ret[0] == 0){
        ret.pop_front();
    }

    return std::move(ret);
}

algo::array
algo::multiplyOneWord(const array &x, integer number) const {
    array ret;
    long_integer carry = 0;
    for(int i = x.size() - 1; i>= 0; i --){
        uint64_t product = (x[i] & LONG_MASK) * number + carry;
        ret.push_front(product & LONG_MASK);
        carry = (product >> 32);
    }
    if(carry){
        ret.push_front(carry);
    }
    while(ret[0] == 0){
        ret.pop_front();
    }

    return std::move(ret);
}

algo::array
algo::multiplyByArray(const array &x, const array &y) const {
    array ret;
    integer xstart = x.size() - 1, ystart = y.size() - 1;
    ret.resize(x.size() + y.size(), 0);
    long_integer carry = 0;
    for(int j = ystart, k = xstart + ystart + 1; j >= 0; j --, k --){
        uint64_t product = (y[j] & LONG_MASK) *
                           (x[xstart] & LONG_MASK) + carry;
        ret[k] = (product & LONG_MASK);
        carry = (product >> 32);
    }
    ret[xstart] = (carry & LONG_MASK);

    for(int i = xstart - 1; i >= 0; i --){
        carry = 0;
        for(int j = ystart, k = i + ystart + 1; j >= 0; j --, k --){
            uint64_t product = (y[j] & LONG_MASK) *
                               (x[i] & LONG_MASK) +
                               (ret[k] & LONG_MASK) + carry;
            ret[k] = (product & LONG_MASK);
            carry = (product >> 32);
        }
        ret[i] = (carry & LONG_MASK);
    }
    // keep ret[0] =/= 0;
    while(ret[0] == 0){
        ret.pop_front();
    }

    return std::move(ret);
}

void
algo::destructiveMulAdd(array &x, integer y, integer z) {
    // multiply word by word
    long_integer ylong = y & LONG_MASK;
    long_integer zlong = z & LONG_MASK;

    long_integer product = 0, carry = 0;
    for(int i = x.size() - 1; i >= 0; i --){
        product = ylong * static_cast<uint32_t>(x[i] & LONG_MASK) + carry;
        x[i] = static_cast<integer>(product & LONG_MASK);
        carry = product >> 32;
    }
    if(carry != 0){
        x.push_front(static_cast<integer>(carry));
    }

    //Perform the addition
    long_integer sum = 0;
    carry = zlong;
    for(int i = x.size() - 1; i >= 0; i --){
        sum = static_cast<uint32_t>(x[i] & LONG_MASK) + carry;
        x[i] = static_cast<integer>(sum & LONG_MASK);
        carry = sum >> 32;
    }
    if(carry != 0){
        x.push_front(static_cast<integer>(carry));
    }
}
/****************************************************************/
///  get function
ExtremeLong::integer
ExtremeLong::digits() const {
    return static_cast<integer>(std::floor(_bitLength_ * std::log10(2.0))) + 1;
}

ExtremeLong::string
ExtremeLong::toString() const{
    if(_signum_ == 0){
        return "0XL";
    }
    string ret ,number;
    if(_signum_ == -1){
        ret += "-";
    }
    if(_mag_.size() == 1){
        number = std::move(std::to_string(_mag_[0]));
    }else{
        auto temp = *this;
        while(temp._signum_ != 0){
            auto tempString = std::move(std::to_string(temp % (1e9)));
            while(tempString.size() < 9){
                tempString.insert(tempString.begin(), '0');
            }
            number.insert(number.begin(), tempString.begin(), tempString.end());
            temp /= 1e9;
        }
    }
    number.erase(0, number.find_first_not_of('0'));
    ret += number;
    return std::move(ret);
}

/// helper functions
ExtremeLong::integer
ExtremeLong::bitLength() {
    int n = 0, len = _mag_.size();
    int magBitLength = ((len - 1) << 5) + func.bitLengthInInt(_mag_[0]);
    if(_signum_ < 0){
        // Check if magnitude is a power of two
        bool pow2 = (func.bitCount(_mag_[0]) == 1);
        for(int i = 1; i < len && pow2; i ++){
            pow2 = (_mag_[i] == 0);
        }
        n = (pow2 ? magBitLength - 1 : magBitLength);
    }else{
        n = magBitLength;
    }

    return n;
}

ExtremeLong
ExtremeLong::negate() const{
    auto ret = *this;
    ret._signum_ *= -1;
    ret._bitLength_ = ret.bitLength();

    return std::move(ret);
}

ExtremeLong::integer
ExtremeLong::compareMagnitude(const ExtremeLong &bigint) const {
    int len1 = _mag_.size();
    int len2 = bigint._mag_.size();
    if(len1 < len2){
        return -1;
    }else if(len1 > len2){
        return 1;
    }else{
        for(int i = 0 ; i < len1; i ++){
            long_integer tempx = static_cast<uint32_t>(_mag_[i]);
            long_integer tempy = static_cast<uint32_t>(bigint._mag_[i]);
            if(tempx != tempy){
                return ((tempx & 0xffffffff) < (tempy & 0xffffffff)) ? -1 : 1;
            }
        }
    }
    return 0;
}

std::pair<ExtremeLong::integer, ExtremeLong>
ExtremeLong::divideOneWord(integer number) const {
    long_integer MASK = 0xffffffffLL;

    if(number == 0){
        throw bad_ExtremeLong("Zero dividend");
    }
    if(number == 1 || number == -1){
        if(number == 1){
            return std::move(std::make_pair(0, ExtremeLong{*this}));
        }else{
            return std::move(std::make_pair(0, ExtremeLong{this->negate()}));
        }
    }
    if(_signum_ == 0){
        return std::move(std::make_pair(0, ExtremeLong{0}));
    }

    ExtremeLong ret;
    long_integer remainder = 0, divisor = number;
    ret._signum_ = _signum_;
    ret._mag_.clear();
    for(int i = 0 ; i < _mag_.size(); i ++){
        long_integer temp = _mag_[i];
        temp &= MASK;
        long_integer dividend = (temp | (remainder << 32));
        long_integer quotient = dividend / divisor;
        remainder = dividend - quotient * divisor;
        ret._mag_.push_back(quotient & MASK);
    }
    if(ret._mag_[0] == 0){
        if(ret._mag_.size() == 1){
            ret._mag_[0] = 1;
            ret._signum_ = 0;
        }else{
            ret._mag_.pop_front();
        }
    }
    ret._bitLength_ = ret.bitLength();

    return std::move(std::make_pair(remainder, ret));
}

/****************************************************************/
/// constructor and destructor

ExtremeLong::ExtremeLong(integer number) {
    if(number == 0){
        _signum_ = 0;
    }else if(number > 0){
        _signum_ = 1;
    }else{
        _signum_ = -1;
        number = - number;
    }
    _mag_.push_front(number);
    _bitLength_ = bitLength();
}

ExtremeLong::ExtremeLong(long_integer number) {
    if(number == 0){
        _signum_ = 0;
    }else if(number > 0){
        _signum_ = 1;
    }else{
        _signum_ = -1;
        number = - number;
    }
    _mag_.push_front(number & 0xffffffff);
    number >>= 32;
    if(number > 0){
        _mag_.push_front(number);
    }
    _bitLength_ = bitLength();
}

ExtremeLong::ExtremeLong(const string& numberString) {
    integer sign = 1, cursor = 0, numDigits;
    integer len = numberString.size();
    auto index1 = numberString.find('-');
    auto index2 = numberString.find('+');
    if(index1 != std::string::npos){
        if(index1 != 0 || index2 != std::string::npos){
            throw bad_ExtremeLong("Illegal big number");
        }else{
            sign = -1;
            cursor = 1;
        }
    }else if(index2 != std::string::npos){
        if(index2 != 0){
            throw bad_ExtremeLong("Illegal big number");
        }else{
            cursor = 1;
        }
    }
    if(numberString.empty()){
        throw bad_ExtremeLong("Zero length BigInteger");
    }
    // Skip leading zeros
    while(cursor < len && numberString[cursor] == '0'){
        cursor ++;
    }
    if(cursor == len){
        _signum_ = 0;
        _mag_.push_front(0);
        _bitLength_ = bitLength();
    }else{
        _signum_ = sign;
        numDigits = len - cursor;
        array magnitude;
        integer firstGroupLen = numDigits % digitPerInt;
        if(firstGroupLen == 0){
            firstGroupLen = digitPerInt;
        }
        _mag_.push_front(func.stringToInt(numberString.substr(cursor, firstGroupLen)));
        cursor += firstGroupLen;
        while(cursor < len){
            func.destructiveMulAdd(_mag_, offsetOfDigitPerInt,
                                   func.stringToInt(numberString.substr(cursor, digitPerInt)));
            cursor += digitPerInt;
        }
        _bitLength_ = bitLength();
    }
}

ExtremeLong::~ExtremeLong() = default;
ExtremeLong::ExtremeLong(const ExtremeLong &bigint) =default;
ExtremeLong::ExtremeLong(ExtremeLong &&bigint) = default;

/****************************************************************/
/// literal define
ExtremeLong
operator"" xl(const char *literalNumber) {
    std::string numberString = literalNumber;
    ExtremeLong ret{numberString};

    return std::move(ret);
}

ExtremeLong
operator"" XL(const char *literalNumber) {
    std::string numberString = literalNumber;
    ExtremeLong ret{numberString};

    return std::move(ret);
}

/****************************************************************/
/// assignment operator overloading
ExtremeLong &
ExtremeLong::operator=(const ExtremeLong & bigint) = default;

ExtremeLong &
ExtremeLong::operator=(ExtremeLong && bigint) = default;
/****************************************************************/
/// operator overloading
ExtremeLong
ExtremeLong::operator+(const ExtremeLong & bigint) const{
    if(bigint._signum_ == 0){
        return *this;
    }else if(_signum_ == 0){
        return bigint;
    }
    ExtremeLong ret;
    if(_signum_ == bigint._signum_){
        ret._mag_ = func.add(this->_mag_, bigint._mag_);
        ret._signum_ = _signum_;
        ret._bitLength_ = ret.bitLength();
    }else{
        if(_signum_ == -1){
            ret = bigint - this->negate();
        }else{
            ret = *this - bigint.negate();
        }
    }
    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator+(long_integer number) const {
    return std::move(*this + ExtremeLong{number});
}

ExtremeLong
ExtremeLong::operator+(const string &numberString) const {
    return std::move(*this + ExtremeLong{numberString});
}

ExtremeLong
ExtremeLong::operator-(const ExtremeLong &bigint) const {
    if(bigint._signum_ == 0){
        return *this;
    }
    ExtremeLong ret;
    if(_signum_ == 0){
        ret = bigint.negate();
    }else if(_signum_ != bigint._signum_){
        if(_signum_ == -1){
            ret = std::move(this->negate() + bigint);
            ret = std::move(ret.negate());
        }else{
            ret = std::move(*this + bigint.negate());
        }
    }else{
        int cmp = compareMagnitude(bigint);
        if(cmp == -1){
            ret._mag_ = func.subtract(bigint._mag_, _mag_);
            ret._signum_ = -1;
            ret._bitLength_ = ret.bitLength();
        }else if(cmp == 1){
            ret._mag_ = func.subtract(_mag_, bigint._mag_);
            ret._signum_ = 1;
            ret._bitLength_ = ret.bitLength();
        }
    }

    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator-(long_integer number) const {
    return std::move(*this - ExtremeLong{number});
}

ExtremeLong
ExtremeLong::operator-(const string &numberString) const {
    return std::move(*this - ExtremeLong{numberString});
}

ExtremeLong
ExtremeLong::operator-() const {
    return std::move(this->negate());
}

ExtremeLong
ExtremeLong::operator*(const ExtremeLong &bigint) const {
    if(_signum_ == 0 || bigint._signum_ == 0){
        return std::move(ExtremeLong{0});
    }
    ExtremeLong ret;
    ret._signum_ = _signum_ * bigint._signum_;
    ret._mag_ = std::move(func.multiplyByArray(_mag_, bigint._mag_));
    ret._bitLength_ = ret.bitLength();

    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator*(integer number) const {
    if(_signum_ == 0 || number == 0){
        return std::move(ExtremeLong{0});
    }
    ExtremeLong ret;
    ret._signum_ = number < 0 ? -_signum_ : _signum_;
    ret._mag_ = std::move(func.multiplyOneWord(_mag_, number));
    ret._bitLength_ = ret.bitLength();

    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator*(const string &numberString) const {
    return std::move(*this * ExtremeLong{numberString});
}

ExtremeLong
ExtremeLong::operator<<(long_integer number) const {
    long_integer nInts = (number >> 5);
    long_integer nBits = (number & 0x1f);
    ExtremeLong ret;
    if(nBits == 0){
        ret._mag_ = _mag_;
        for(long_integer i = 0; i < nInts; i ++){
            ret._mag_.push_back(0);
        }
        ret._signum_ = _signum_;
        ret._bitLength_ = ret.bitLength();
    }else{
        ret._mag_.pop_front();
        long_integer idx = 0;
        long_integer numIter = _mag_.size() - 1;
        long_integer shiftCount = nBits, shiftCountRight = 32 - nBits;
        uint32_t right;
        while(idx < numIter){
            right = _mag_[idx + 1];
            ret._mag_.push_back((_mag_[idx] << shiftCount) | (right >> shiftCountRight));
            idx ++;
        }
        ret._mag_.push_back(_mag_[numIter] << shiftCount);
        right = _mag_[0];
        if((right >> shiftCountRight) != 0){
            ret._mag_.push_front(right >> shiftCountRight);
            for(long_integer i = 0; i < nInts; i ++){
                ret._mag_.push_back(0);
            }
        }else{
            for(long_integer i = 0; i < nInts; i ++){
                ret._mag_.push_back(0);
            }
        }
        ret._signum_ = _signum_;
        ret._bitLength_ = ret.bitLength();

    }

    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator>>(long_integer number) const {
    long_integer nInts = (number >> 5);
    long_integer nBits = (number & 0x1f);
    if(number >= _bitLength_){
        return std::move(ExtremeLong{0});
    }
    ExtremeLong ret;
    if(nBits == 0){
        ret._mag_ = _mag_;
        for(long_integer i = 0; i < nInts; i ++){
            ret._mag_.pop_back();
        }
        ret._signum_ = _signum_;
        ret._bitLength_ = ret.bitLength();
    }else{
        long_integer idx = _mag_.size() - nInts - 1;
        long_integer shiftCount = nBits, shiftCountLeft = 32 - nBits;
        while(idx > 0){
            uint32_t right = _mag_[idx], left = _mag_[idx - 1];
            ret._mag_.push_front((right >> shiftCount) | (left << shiftCountLeft));
            idx --;
        }
        uint32_t right = _mag_[0];
        if((right >> shiftCount) != 0){
            ret._mag_.push_front(right >> shiftCount);
        }
        ret._mag_.pop_back();
        ret._signum_ = _signum_;
        ret._bitLength_ = ret.bitLength();
    }

    return std::move(ret);
}

ExtremeLong
ExtremeLong::operator/(integer number) const {
    auto res = divideOneWord(number);
    auto ret = res.second;

    return std::move(ret);
}

ExtremeLong::integer
ExtremeLong::operator%(integer number) const {
    auto res = divideOneWord(number);
    auto ret = res.first;

    return ret;
}

/****************************************************************/
ExtremeLong
ExtremeLong::operator+=(const ExtremeLong &bigint) {
    *this = std::move(*this + bigint);
    return *this;
}

ExtremeLong
ExtremeLong::operator+=(long_integer number) {
    *this = std::move(*this + number);
    return *this;
}

ExtremeLong
ExtremeLong::operator+=(const string & numberString) {
    *this = std::move(*this + numberString);
    return *this;
}

ExtremeLong
ExtremeLong::operator-=(const ExtremeLong &bigint) {
    *this = std::move(*this - bigint);
    return *this;
}

ExtremeLong
ExtremeLong::operator-=(long_integer number) {
    *this = std::move(*this - number);
    return *this;
}

ExtremeLong
ExtremeLong::operator-=(const string & numberString) {
    *this = std::move(*this - numberString);
    return *this;
}

ExtremeLong
ExtremeLong::operator*=(const ExtremeLong &bigint) {
    *this = std::move(*this * bigint);
    return *this;
}

ExtremeLong
ExtremeLong::operator*=(long_integer number) {
    *this = std::move(*this * number);
    return *this;
}

ExtremeLong
ExtremeLong::operator*=(const string & numberString) {
    *this = std::move(*this * numberString);
    return *this;
}

ExtremeLong
ExtremeLong::operator/=(integer number) {
    *this = std::move(*this / number);
    return *this;
}
/****************************************************************/
ExtremeLong
operator+(ExtremeLong::long_integer number, const ExtremeLong &bigint) {
    return std::move(bigint + number);
}

ExtremeLong
operator-(ExtremeLong::long_integer number, const ExtremeLong &bigint) {
    return std::move(bigint - number);
}

ExtremeLong
operator*(ExtremeLong::long_integer number, const ExtremeLong &bigint) {
    return std::move(bigint * number);
}

/****************************************************************/
// fast pow algorithm(divide and conquer)
ExtremeLong
ExtremeLong::operator*(const ReturnNumber<long>& ruNumber) const {
    return std::move(ExtremeLong{*this ^ ruNumber.item()});
}

ExtremeLong
ExtremeLong::operator^(long_integer number) const {
    if(number == 0){
        return std::move(ExtremeLong{1});
    }else if(number == 1){
        return std::move(ExtremeLong{*this});
    }else{
        ExtremeLong temp;
        if(number % 2 == 0){
            temp = std::move(*this ^ (number / 2));
            return std::move(temp * temp);
        }else{
            temp = std::move(*this ^ (number / 2));
            return std::move(temp * temp * (*this));
        }
    }
}
/****************************************************************/
/// cin and cout operator overload
std::ostream &
operator<<(std::ostream & os, const ExtremeLong & bigInteger){
    os << bigInteger.toString();

    return os;
}

std::istream &
operator>>(std::istream & is, ExtremeLong & bigInteger){
    std::string temp;
    is >> temp;
    bigInteger = std::move(ExtremeLong(temp));
    return is;
}
