#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void update(int *a, int *b) {
    int sum = *a + *b;
    int dif = abs(*a - *b);
    *a = sum;
    *b = dif;
};

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    update(&a, &b);
    cout << a << endl;
    cout << b << endl;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
