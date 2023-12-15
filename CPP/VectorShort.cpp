#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin >> N;
    vector<int> v;

    while(N--){
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    for(int d:v){
        cout << d << " ";
    }
    cout << endl;
    return 0;
}
