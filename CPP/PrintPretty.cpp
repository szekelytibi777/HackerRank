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

int main() {
    fs::current_path("D:\\WORK\\HackeRank\\CPP");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ofstream o("out.txt");

    int T;
    cin >> T;
    while(T--){
        double A,B,C;
        cin >> A >> B >> C;
        std::stringstream ss;
        ss << fixed << setprecision(2) << (B < 0 ? '-' : '+' ) << B;
        string bs = ss.str();
        int n = 15-bs.size();
        string repeat(n, '-');
     
        cout << "0x" << hex << int(A) << endl; 
        cout << repeat << bs << endl;
        cout << ToString(C);

    }
    return 0;
}