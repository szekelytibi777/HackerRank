#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int array_index;
    int element_index;
}Query;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, qn;
    cin >> n;
    cin >> qn;
    vector<int> arrays[n];
    // Read arrays from standard input
    for(int i = 0; i < n;){
        string line;
        getline(cin, line);
        istringstream iss(line);
        if(!line.empty()){
            int n;
            while ( iss >> n) {    
                arrays[i].push_back(n);
            }
            i++;
        }
    }
    // Read queries from standard input
    vector<Query> queries;
    for(int qi = 0; qi < qn; qi++){
        Query query;
        cin >> query.array_index;
        cin >> query.element_index;
        queries.push_back(query);
    }
    for(Query q : queries){
        cout << arrays[q.array_index][q.element_index+1] << endl;
    }
    return 0;
}
