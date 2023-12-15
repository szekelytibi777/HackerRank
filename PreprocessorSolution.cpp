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
    vector<int> v(N);
    while(N--){
        int e;
        cin >> e;
        v.push_back(e);
    }
    int max_v = *max_element(v.begin(), v.end());
    int min_v = *min_element(v.begin(), v.end());
    cout << "Result = " << (max_v - min_v) << endl;
    return 0;
}
