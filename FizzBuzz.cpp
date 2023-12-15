#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void fizzBuzz(int n) {
    for(int i = 1; i <= n; i++) {
        bool multipleOf3 = i % 3 == 0;
        bool multipleOf5 = i % 5 == 0;
        if(multipleOf3 && multipleOf5) 
            cout << "FizzBuzz" << endl;
        else if(multipleOf3)
            cout << "Fizz" << endl;
        else if(multipleOf5)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

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
