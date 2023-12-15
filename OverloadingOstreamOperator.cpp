#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    private:
        string fn_;
        string ln_;
    public:
        Person(const string& fn, const string& ln)
        : fn_(fn)
        , ln_(ln)
        {}
        friend ostream& operator<<(ostream& os, const Person& dt);
};

ostream& operator<<(ostream& os, const Person& dt)
{
    os << "first_name=" << dt.fn_ << ",last_name=" << dt.ln_;
    return os;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string first_name;
    string last_name;
    string value;
    cin >> first_name >> last_name >> value;
    Person p(first_name, last_name);
    cout << p << " " << value << endl;
    return 0;
}
