//
//  Annlie Nguyen
//  rec08
//
//  Operator Overloading with Rational Class
//

#include <iostream>
#include <string>
using namespace std;

class Rational {
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(Rational& lhs, Rational& rhs);
    friend istream& operator>> (istream& is, Rational& rhs);
    friend ostream& operator<< (ostream& os, const Rational& rhs);
    
private:
    int numer = 0;
    int denom = 1;
    
public:
    Rational(int numer=0, int denom=1) : numer(numer), denom(denom) {
        normalize();
    }
    //    Rational(int num) : numer(num), denom(1) {
    //        normalize();
    //    }
    //    Rational() : numer(1), denom(1) {}
    
    int helpNormalize(int numer, int denom) {
        while (denom != 0) {
            int storeLeft = numer % denom;
            numer = denom;
            denom = storeLeft;
        }
        return numer;
    }
    
    void normalize() {
        int divisor = helpNormalize(numer, denom);
        numer = numer/divisor;
        denom = denom/divisor;
        
        if (denom < 0) {
            numer *= -1;
            denom *= -1;
        }
    }
    
    Rational& operator+=(const Rational& rhs) {
        numer = (numer*rhs.denom) + (denom*rhs.numer);
        denom = (denom*rhs.denom);
        normalize();
        return *this;
    }
    
    Rational& operator++() { //PRE INCREMENT
        numer += denom;
        normalize();
        return *this;
    }
    
    Rational operator++(int) { //POST INCREMENT
        Rational origCopy(*this);
        numer += denom;
        normalize();
        return origCopy;
    }
    
    explicit operator bool() const {
        return numer!= 0;
    }
}; //end of rational class

//function declarations:
//DONT REDECLARE FRIEND FUNCTIONS
Rational operator+(const Rational& lhs, const Rational& rhs);

//bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);

Rational& operator--(Rational& rhs);
Rational operator--(Rational& rhs, int);

//bool operator<(Rational& lhs, Rational& rhs);
bool operator>(Rational& lhs, Rational& rhs);
bool operator<=(Rational& lhs, Rational& rhs);
bool operator>=(Rational& lhs, Rational& rhs);

//istream& operator>> (istream& is, Rational& rhs);
//ostream& operator<< (ostream& os, Rational& rhs);

int normalize(int numer, int denom);
//end of function declarations

int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;
    
    Rational a, b;
    cout << "Input two rational numbers.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Rational one(1);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;    // Implement as member
    cout << "a = " << a << endl;
    
    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;
    
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;
    
    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;
    
    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;
    
    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    // cout << "a-- -- = " << (a-- --) << endl;
    // cout << "a = " << a << endl;
    
    
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
} //end of main


Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational copy(lhs);
    copy += rhs;
    return copy;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.numer == rhs.numer) && (lhs.denom == rhs.denom);
}
bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs==rhs);
}

Rational& operator--(Rational& rhs) { //PRE
    Rational arith(-1);
    rhs += arith;
    return rhs;
}

Rational operator--(Rational& rhs, int) { //POST, return copy
    Rational origCopy(rhs);
    //Rational copy(-1);
    rhs += -1;
    return origCopy;
}

bool operator<(Rational& lhs, Rational& rhs) {
    return (lhs.numer/lhs.denom) < (rhs.numer/rhs.denom);
}
bool operator>(Rational& lhs, Rational& rhs) {
    return (!(lhs < rhs) && !(lhs==rhs));
}

bool operator<=(Rational& lhs, Rational& rhs) {
    //return (lhs < rhs) || (lhs==rhs);
    return !(lhs > rhs);
}
bool operator>=(Rational& lhs, Rational& rhs) {
    return !(lhs < rhs);
}

istream& operator>> (istream& is, Rational& rhs) {
    int userNum = 0;
    int userDen = 0;
    char slash;
    is >> userNum >> slash >> userDen;
    
    rhs = Rational(userNum, userDen);
    
    return is;
}

ostream& operator<< (ostream& os, const Rational& rhs) {
    if ( (rhs.numer / rhs.denom) == rhs.numer ) {
        os << rhs.numer;
    } else {
        os << rhs.numer << '/' << rhs.denom;
    }
    return os;
}

