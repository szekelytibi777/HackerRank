#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int start_up() { ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }
int static r = start_up();

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


struct RangeParams
{
    unsigned long long *p;
    int n;
    int v;
    bool init;

    RangeParams(unsigned long long *p_, int n_, int v_, bool init_)
    :   p(p_)
    ,   n(n_)
    ,   v(v_)
    ,   init(init_)
    {}
};

void *accumulate_range(void* arg)
{
    RangeParams *rp =(RangeParams *)arg;
    unsigned long long *p = rp->p;
    int n = rp->n;
    int t = rp->v;

    if(rp->init){
        while(n--){
            *p = t;
            p++;
        };
    }
    else{
        while(n--){
            *p += t;
            p++;
        };
    }

    return 0;
}

long arrayManipulation(int n, vector<vector<int>>& queries) {
    vector<unsigned long long> v(n, 0);
    int num_queries = queries.size();
    int ccc = 0;
    const int num_threads = 256;
    vector<pthread_t> threads(num_threads);
    auto time_prev = high_resolution_clock::now(); 
    bool init = true;
    while(ccc < num_queries){
        int thread_index = ccc % num_threads;
        vector<int>& a = queries[ccc];
        unsigned int b = a[0]-1;
        unsigned int e = a[1];
        int t = a[2];
        RangeParams rp(&v[b], e-b, t, init);
        //accumulate_range((void*)&rp);

        pthread_t &th = threads[thread_index];
        pthread_create(&th, NULL, accumulate_range, (void*)&rp);
        init = false;
        ccc++;
    };

    for(pthread_t& th:threads)
    {
        pthread_join( th, NULL); 
    }

    auto time_now = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(time_now - time_prev);
    time_prev = time_now;
    auto res = max_element(v.begin(), v.end());
    auto duration2 = duration_cast<milliseconds>(high_resolution_clock::now() - time_prev);

    cout << duration1.count() << ", " << duration2.count() << endl;
    return *res;
};


#define TEST 0
#if TEST
    #define CIN fin
#else
    #define CIN cin
#endif

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin("ArrayManipulationinput07.txt");

    // fin.ignore(numeric_limits<streamsize>::max(), '\n');
    string first_multiple_input_temp;
    getline(CIN, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(CIN, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));
        if(!queries_row_temp[0].empty()){
            for (int j = 0; j < 3; j++) {
                int queries_row_item = stoi(queries_row_temp[j]);

                queries[i][j] = queries_row_item;
            }
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << endl;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
