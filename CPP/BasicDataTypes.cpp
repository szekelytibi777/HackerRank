#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    // Complete the code.
    int i;
    long long l;
    char c;
    float f;
    double d;
    cin >> i;
    cin >> l;
    cin >> c;
    cin >> f;
    cin >> d;
    
    cout << i << endl;
    cout << l << endl;
    cout << c << endl;
    cout << fixed << setprecision(3) << f << endl;
    cout << fixed << setprecision(9) << d << endl;
    return 0;
}