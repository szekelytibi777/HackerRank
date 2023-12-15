#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

class Matrix{
    private:
        vector<vector<int>> v;
        int rows;
        int columns;
    public:
        Matrix(int num_rows, int num_columns)
        : rows(num_rows)
        , columns(num_columns)
        {
            v.reserve(num_rows);
            v.resize(num_rows);
            for(vector<int>& row:v){
                row.reserve(num_columns);
                row.resize(num_columns);

            }

        }

        ~Matrix(){
            for(vector<int> &rows: v)
                rows.clear();
            v.clear();
        }

        int& at(int ri, int ci){
            return v[ci][ri];
        }

        string to_string(){
            stringstream ss;
            for(vector<int>& row: v){
                for(int e : row)
                    ss << e << " ";
                ss << "\n";
            }
            return ss.str();
        }

        Matrix operator +(Matrix& other){
            Matrix res(rows, columns);
            for(int j = 0; j < rows; j++)
                for(int i = 0; i < columns; i++)
                    res.at(i, j) = this->at(i, j) + other.at(i, j);
            return res;
        }
};

#define TEST 0
#if TEST
    #define CIN ifs
#else
    #define CIN cin
#endif

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ifstream ifs("OperatorOverloadinginput01.txt");
    int T;
    CIN >> T;
    while(T--){
        int N, M;
        CIN >> N >> M;
        Matrix m1(N, M);
        Matrix m2(N, M);
        for(int j = 0; j < N ; j++)
            for(int i = 0; i < M; i++)
                CIN >> m1.at(i, j);
        for(int j = 0; j < N ; j++)
            for(int i = 0; i < M; i++)
                CIN >> m2.at(i, j);
        //cout << m1.to_string();
        //cout << m2.to_string();
        cout << (m1 + m2).to_string();


    }  
    return 0;
}