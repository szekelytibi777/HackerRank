#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    vector<pair<int , int>> tcs(t);
    string colors[] = {"red", "green", "orange"};
    string fruits[] = {"apple", "orange", "pear"};
    int cn = 3;
    int fn = 3;
    for(int i = 0; i < t; i++){
        int c, f;
        cin >> c;
        cin >> f;
        tcs[i] = make_pair(c, f);
    }
    for(auto tc : tcs){
        int c = tc.first;
        int f = tc.second;
        string cs = c >= 0 && c < cn ? colors[c] : "unknown";
        string fs = f >= 0 && f < fn ? fruits[f] : "unknown";
        cout << cs << " " << fs << endl;  
    }

    return 0;
}
