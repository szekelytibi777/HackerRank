#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q, x, y;
    set<int> s;
    cin >> Q;
    while(Q--){
        cin >> y >> x;
        switch(y){
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(x);
                break;
            case 3:
                set<int>::iterator itr = s.find(x);
                if(itr == s.end())
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;

                break;
        }

    }   
    return 0;
}
