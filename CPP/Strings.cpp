#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a,b,c,d,e;
    cin >> a;
    cin >> b;
    c = a + b;
    d = a;
    e = b;
    e[0] = a[0];
    d[0] = b[0];

    cout << a.size() << " " << b.size() << endl;
    cout << c << endl;
    cout << d << " " << e << endl;

    return 0;
}
