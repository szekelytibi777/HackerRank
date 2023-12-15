#include <bits/stdc++.h>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, i;
    char *str[] = {"one","two","three","four","five","six","seven","eight","nine","even","odd"};
    cin >> a;
    cin >> b;
    for(i = a; i <= b; i++)
    {
        if(i<=9)
        {
            cout<<str[i-1]<<"\n";
        }
        else
        {
            cout<<str[9+(i%2)]<<"\n";
        }
    }
}


