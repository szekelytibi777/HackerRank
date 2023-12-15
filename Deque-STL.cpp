#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>
#include <fstream>
#include <chrono>
using namespace std;

#define TEST 0
#define PRINT 0

#if TEST
    #define CIN ifs
#else
    #define CIN cin
#endif

typedef struct Data{
    int K, N;
    int *a;
    Data(int n = 0, int k = 0)
    : N(n)
    , K(k)
    , a(0)
    { }

    void create(int n, int k){
        N = n;
        K = k;
        a = new int[n];
    }

    ~Data(){
        if(a)
            delete[] a;
    }
}Data;

void printKMax(int arr[], int n, int k)
{
	//Write your code here.
	/* Deque-STL in C++ - Hacker Rank Solution START */
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    for ( ; i < n; i++) {
        std::cout << (arr[Qi.front()]) << " ";
        while ((!Qi.empty()) && (Qi.front() <= i - k))
            Qi.pop_front();
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    std::cout << arr[Qi.front()] << endl;
    /* Deque-STL in C++ - Hacker Rank Solution END */
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ifstream ifs("Deque_input01.txt");
    int C;
    CIN >> C;   
    vector<Data> datas(C);
    for(int j = 0;j < C; j++){
        int N;
        int K;
        CIN >> N >> K;
        Data &d = datas[j];
        d.create(N, K);
        
        for(int i = 0; i < N; i++){
            int v;
            CIN >> v;
            d.a[i] = v;
        }
    }
    for(const Data &d:datas){
        printKMax(d.a, d.N, d.K);
    }

    return 0;
}
