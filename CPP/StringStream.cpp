#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {

    string line;
    vector<int> out;
    cin >> line;
    stringstream ss(line);
    for (int i; ss >> i;) {
        out.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (std::size_t i = 0; i < out.size(); i++)
        std::cout << out[i] << std::endl;
    
    return 0;
}
