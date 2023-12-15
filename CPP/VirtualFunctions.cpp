#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        virtual void getData(){
            cin >> name;
            cin >> age;
        }

        virtual void putData(){
            cout << name << " " << age;
        }

};

class Professor : public Person{
    public:
        int publications;
        int cur_id;

        Professor(){
            static int ID = 1;
            cur_id = ID++;
        }

        virtual void getData(){
            Person::getData();
            cin >> publications;
        }

        virtual void putData(){
            Person::putData();
            cout << " " << publications << " " << cur_id << endl;
        }
    
};

class Student : public Person{
    public:
        int marks[6];
        int cur_id;

        Student(){
            static int ID = 1;
            cur_id = ID++;
        }

        virtual void getData(){
            Person::getData();
            for(int i = 0; i< 6; i++){
                cin >> marks[i];
            }
        }

        virtual void putData(){
            Person::putData();
            int sum_of_marks = 0;
            for(int mark : marks){
                sum_of_marks += mark;
            }
            cout << " " << sum_of_marks << " " << cur_id << endl;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    vector<Person *> persons (n);
    int i = 0;
    while(i < n){
        int type;
        cin >> type;
        if(type == 1){
            Professor* prof = new Professor();
            persons[i] = prof;
        }
        else if (type == 2){
            Student *student = new Student();
            persons[i] = student;
        }
        if(persons[i])
            persons[i]->getData();
        i++;
    }

    for(Person *person : persons){
        if(person)
            person->putData();
    }
    return 0;
}
