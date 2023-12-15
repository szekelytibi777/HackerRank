#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream> 
using namespace std;

class Student{
    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        int get_age() {
            return age;
        }
        void set_age(const int value){
            age = value;
        }

        const string& get_first_name() {
            return first_name;
        }
        void set_first_name(const string value){
            first_name = value;
        }

        const string& get_last_name() {
            return last_name;
        }
        void set_last_name(const string value){
            last_name = value;
        }

        int get_standard() {
            return standard;
        }
        void set_standard(const int value){
            standard = value;
        }

        string to_string(){
            stringstream ss;
            ss << age << "," << first_name << "," << last_name << "," << standard;
            return ss.str(); 
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int age, standard;
    string fname, lname;
    cin >> age;
    cin >> fname;
    cin >> lname;
    cin >> standard;

    Student student;
    student.set_age(age);
    student.set_first_name(fname);
    student.set_last_name(lname);
    student.set_standard(standard);

    cout << student.get_age() << endl;
    cout << student.get_last_name() << ", " << student.get_first_name() << endl;
    cout << student.get_standard() << endl;
    cout << endl;
    cout << student.to_string() << endl;



    return 0;
}
