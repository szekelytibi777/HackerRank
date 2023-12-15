#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Complex
{
public:
    int real, imag;

    Complex(int r = 0, int i = 0)
    : real(r)
    , imag(i)
    {}

    Complex operator+(Complex& other){
        Complex res;
        res.real = real+other.real;
        res.imag = imag+other.imag;
        return res;
    } 

    friend ostream & operator << (ostream &out, const Complex &c);
    
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag;
    return out;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int r, i;
    string istr;

    cin >> r >> istr;
    i = stoi(istr.substr(2));
    Complex c1(r, i);

    cin >> r >> istr;
    i = stoi(istr.substr(2));
    Complex c2(r, i);

    cout << c1 << endl;
    cout << c2 << endl;
    cout << (c1+c2) << endl;

    


    return 0;
}
