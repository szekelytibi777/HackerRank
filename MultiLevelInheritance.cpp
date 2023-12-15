#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
    public:
        virtual string name(){
            return "I am a triangle";
        }
};

class Equilateral : public Triangle{
    public:
        virtual string name(){
            return "I am an equilateral triangle";
        }
};

class Isosceles : public Triangle{
    public:
        virtual string name(){
            return "I am an isosceles triangle";
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Triangle *triangles[] = {new Equilateral(), new Isosceles(), new Triangle()};
    for(Triangle* t : triangles){
        cout << t->name() << endl;
    }
    return 0;
}
