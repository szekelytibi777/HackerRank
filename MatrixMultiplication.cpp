#include <chrono>
#include <iostream>
#include <thread>
#include <array>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

template<size_t ColCount>
using RowT=std::array<int, ColCount>;

template<size_t RowCount, size_t ColCount>
using MatrixT=std::array<RowT<ColCount>, RowCount>;

/*
Given
 - a matrix m1 with integer values and M rows and N columns
 - a matrix m2 with integer values and N rows and Z columns
When 
 - we multiply m1 and m2 with your implemented matrixMultiplicaton function
Then:
 -  we receive a result matrix based on the rules described here: https://en.wikipedia.org/wiki/Matrix_multiplication


Example:
  [ 1 2 ]   [ 1 2 3 ]    [ 9  12 15 ]
  [ 3 4 ] * [ 4 5 6 ]  = [ 19 26 33 ]    where e.g.: result[0][0] == 9 == m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0] == 1*1 + 2*4
  [ 5 6 ]                [ 29 40 51 ]                result[0][1] == 12 == m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1] == 1*2 + 2*5

Notes: 
    The dimensions of matrices are template parameters. 
    Check MatrixT type alias above, and the printMatrix function below.
    You will have to fill in the template parameters in the matrixMultiplicaton function.


Optional Bonus:
    Try to optimize the calculation by using multiple thread        
*/
#define FASTER
template< size_t M, size_t N, size_t Z >
MatrixT<M, Z> matrixMultiplicaton(MatrixT<M, N> m1, MatrixT<N, Z> m2)
{
    MatrixT<M, Z> res;
    //int *pr = &res[0][0];
    for(int m = 0; m < M; m++){
        #ifdef FASTER
            int *pm2 = &m2[m][0];
        #endif
        for(int z = 0; z < Z; z++){
            #ifdef FASTER
                int *pr = &res[m][z];
                *pr = 0;
            #else
                res[m][z] = 0;
            #endif
            for(int n = 0; n < N; n++){
                #ifdef FASTER
                    *pr += m1[m][n] * m2[n][z];
                #else
                    res[m][z] += m1[m][n] * m2[n][z];
                #endif
            }
        }
    }
    return res;
}

template<size_t rows, size_t cols>
void printMatrix(const MatrixT<rows, cols>& m, ofstream& outs)
{
    for (auto row : m)
    {
        for (auto cell : row){
            outs  << cell  << " ";
            outs << '\n';

            cout << cell << " ";
        } 
        cout << endl;
    }
}

int main()
{
    #if 1
    string oname("out.txt");
    #else
    string oname (getenv("OUTPUT_PATH")); 
    #endif
    ofstream fout(oname);
    string input;
    getline(cin, input);

    if(input=="test_case1")
    {
        MatrixT<3,2> m1 = {RowT<2>{1,2}, 
                           RowT<2>{3,4},
                           RowT<2>{5,6}};
        
        MatrixT<2,3> m2 = {RowT<3>{1,2, 3}, 
                           RowT<3>{4, 5, 6}};
        
       printMatrix(matrixMultiplicaton(m1, m2), fout);
    }else if(input=="test_case2")
    {

        MatrixT<4,3> m1 = {RowT<3>{1,2,3}, 
                           RowT<3>{3,4,5}, 
                           RowT<3>{5,6,12},
                           RowT<3>{5,6, 0} };
        MatrixT<3,3> m2 = {RowT<3>{1,0, 0}, 
                           RowT<3>{0, 1, 0},
                           RowT<3>{0, 0, 1}};
        printMatrix(matrixMultiplicaton(m1, m2), fout);
        
    }else if(input =="test_case3")
    {
        constexpr size_t M = 700, N = 600;
        
        MatrixT<M,N> m1;                
        int val = 0;
        for (size_t i = 0; i < M; i++)
            for (size_t j = 0; j < N; j++) m1[i][j] = val++;
    
        MatrixT<N,N> m2;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++) m2[i][j] = (i == j) ? 1 : 0;
    
        
        auto t_start = std::chrono::high_resolution_clock::now();
        MatrixT<M, N> result = matrixMultiplicaton(m1, m2);
        auto t_end = std::chrono::high_resolution_clock::now();
        double time_taken =  std::chrono::duration<double, std::milli>(t_end-t_start).count();
       
        
        bool good = true;
        for (size_t i = 0; i < M; i++)
            for (size_t j = 0; j < N; j++) 
              if (m1[i][j] != result[i][j]) good = false;

        fout << (good ? "good"s : "wrong result"s) << '\n';
        fout << "time " << (time_taken > 200 ? "too_slow"s : "ok"s) << '\n';
        #ifdef FASTER
            cout << "time: " << time_taken << (time_taken > 200 ? "too_slow"s : "ok"s) << '\n';
        #endif
    }

    
    fout.close();

    return 0;
}
