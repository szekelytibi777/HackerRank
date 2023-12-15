#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int largest_proper_divisor(int n){
    if(n==0 || n==1)
        throw(invalid_argument("largest proper divisor is not defined for n="+to_string(n)));
    else{
        int ld = -1;
        for(int i = 1; i != n; i++){
            if(n % i == 0)
                ld = i;
        }
        return ld;
    }
}
       

void process_input(int n){
    try{
        int lpd = largest_proper_divisor(n);
        cout << "result=" << lpd << endl;

    }
    catch(invalid_argument e){
        cout << e.what() << endl;
    }
    cout << "returning control flow to caller" << endl;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    process_input(n);
     
    return 0;
}
