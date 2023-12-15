#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */


typedef long long ll;

template<size_t S, typename T> 
using ExtraLongInt=array<T, S>;   

template<size_t S, typename T>
ExtraLongInt<S, T> multiply(ExtraLongInt<S, T>& a, T b){
    ExtraLongInt<S, T> res;
    return a;
}

template<size_t S, typename T>
string toString(ExtraLongInt<S, T> &a ){
    string ret;
    stringstream ss;
    for(T t:a){
        ss << t;
    }
    return ss.str();
}

template<size_t S, typename T>
void clear(ExtraLongInt<S, T>& a){
    for(int i = 0; i < S; ++i){
        a[i] = 0;
    }
}

void extraLongFactorials(int n) {
    ExtraLongInt<10, unsigned char> a;
    clear(a);
    for (int i = 0; i < n; i++) {
        unsigned char b = n - i ;
        a = multiply(a, b);
    }
    cout << toString(a) << endl;
}

int extraLongFactorials2(int n) {
    int number[300] = {};
    number[0] = 1;
    int len = 1;
    for (int i = 2; i <= n; ++i) {
        for (int pos = 0, r = 0; pos < len || r != 0; ++pos) {
            if (pos < len)
                r += number[pos] * i;
            else
                ++len;
            number[pos] = r % 10;
            r /= 10;
        }
    }
    for (int i = len - 1; i >= 0; --i)
        cout << number[i];
    return 0;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials2(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
