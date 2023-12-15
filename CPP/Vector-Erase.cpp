#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define IN cin
int main(int argc, char **argv) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, x, a, b;
    IN >> N;
    vector<unsigned int> v(N);
    v.clear();
    int c = N;
    while(c--){
        unsigned int d;
        IN >> d;
        v.push_back(d);
    }
    IN >> x;
    IN >> a >> b;
    x = x-1;
    a = a-1;
    b = b-1;
    v.erase(v.begin()+x);
    v.erase(v.begin()+a, v.begin()+b);
    

    cout << v.size() << endl;
    for(unsigned int d: v){
        cout << d << " ";
    }

    cout << endl;
    return 0;
}
