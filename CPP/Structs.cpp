#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Student{
    int age;
    string firstName;
    string lastName;
    int standard;
    string toString(){
        string ret = to_string(age) + " " + firstName + " " + lastName + " " + to_string(standard);
        return ret;
    };
};

int main() {
    Student student;
    cin >> student.age;
    cin >> student.firstName;
    cin >> student.lastName;
    cin >> student.standard;

    cout << student.toString() << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
