#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q, t, m;
    string n;
    map<string, int> s;
    cin >> Q;
    while(Q--){
        cin >> t;
        switch(t){
            case 1:
                cin >> n >> m;
                    if(s.count(n))
                        s[n] += m;
                    else
                        s[n] = m;
                break;
            case 2:
                cin >> n;
                s.erase(n);
                break;
            case 3:
                cin >> n;
                if(s.count(n))
                    cout << s[n] << endl;
                else
                    cout << 0 << endl;
                break;
        }

    }     
    return 0;
}
