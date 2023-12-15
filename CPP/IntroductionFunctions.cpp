#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    int m = max(max(a, b), max(c, d));
    return m;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    int m = max_of_four(a, b, c, d);
    cout << m << endl;

    return 0;
}
