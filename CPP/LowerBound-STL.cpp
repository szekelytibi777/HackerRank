#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

//#define TEST
#ifdef TEST
    #define IN ifs
    #define OUT ofs
#else
    #define IN cin
    #define OUT cout
#endif

int main(int argc, char *argv[]) {
    
    string p(argv[0]);
    size_t pos = p.find_last_of('\\');
    string path = p.substr(0, pos+1);
    path += "TESTS";
    fs::current_path(path);   

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ifstream ifs("LowerBoundinput11.txt");
    ofstream ofs("myfile.txt");
    

    int N, Q;
    IN >> N;
    vector<int> v(N);
    v.clear();
    int c = N;
    while(c--){
        int d;
        IN >> d;
        v.push_back(d);
    }
    IN >> Q;
    vector<int> q(Q);
    q.clear();
    c = Q;
    while(c--){
        int d;
        IN >> d;
        q.push_back(d);
    }
    int minimum = *min_element(v.begin(), v.end());
    int maximum = *max_element(v.begin(), v.end());
    for(int val : q){
        vector <int>::iterator low = lower_bound(v.begin(), v.end(), val);
        if (v[low - v.begin()] == val)
            cout << "Yes " << (low - v.begin() + 1) << endl;
        else
            cout << "No " << (low - v.begin() + 1) << endl;
    }

    return 0;
}
