#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A , public B , public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
           // Multiply by 2
            while (new_val % 2 == 0) {
                new_val = new_val / 2;
                A::func(this->val);
            }
            // Multiply by 3
            while (new_val % 3 == 0) {
                new_val = new_val / 3;
                B::func(this->val);
            }
            // Multiply by 5
            while (new_val % 5 == 0) {
                new_val = new_val / 5;
                C::func(this->val);
            }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    D d;
    int N;
    cin >> N;
    d.update_val(N);  
    cout << "Value = " << N << endl;
    cout << "A's func called " << d.getA() << " times" << endl;
    cout << "B's func called " << d.getB() << " times" << endl;
    cout << "C's func called " << d.getC() << " times" << endl;
    return 0;
}
