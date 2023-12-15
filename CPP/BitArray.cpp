#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<int, int> distinct_integers;
    unsigned int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    vector<unsigned int> a(N);
    a[0] = S % (2 ^ 31);
    for(unsigned int i = 1; i < N; i++){
        a[i] = Q % (2 ^ 31);
    }
    for(unsigned int n : a){
        distinct_integers[n] = n;
    }
    cout << distinct_integers.size() << endl;
    return 0;
}
