#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> 
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

template <typename T>
inline std::string ToString(T value) {
    std::stringstream out;
    out << setprecision(9) << scientific << uppercase;  
    out << value;
    return out.str();
}

typedef struct{
    double A, B, C;
}Data;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ofstream o("out.txt");

    int T;
    cin >> T;
    vector<Data> dv(T);
    dv.clear();
    while(T--){
        Data d;
        cin >> d.A >> d.B >> d.C;
        dv.push_back(d);
    }
    for(Data &d : dv){
        std::stringstream ss;
        ss << fixed << setprecision(2) << (d.B < 0 ? '-' : '+' ) << d.B;
        string bs = ss.str();
        int n = 15-bs.size();
        string repeat(n, '_');
     
        cout << "0x" << hex << (long long)(d.A) << endl; 
        cout << repeat << bs << endl;
        cout << ToString(d.C) << endl;
    }
    return 0;
}