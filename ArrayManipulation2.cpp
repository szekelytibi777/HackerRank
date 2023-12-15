#include <bits/stdc++.h>
#include <algorithm>
#include <parallel/algorithm>
#include <filesystem>
#include <thread>
#include <chrono>


using namespace std;
using namespace chrono;
const int MAX_THREADS = 8;

int start_up() { ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }
int static r = start_up();

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>>& queries, vector<long long>& v) {
    int num_queries = queries.size();
    int ccc = 0;
    auto time_prev = chrono::high_resolution_clock::now();
    long long max_value = INT64_MIN;
    int qc = 0;
    for(auto q: queries){
        //int num = q[1] - q[0];
        long long *b = &v[q[0]-1];
        long long *e = &v[q[1]];
        int t = q[2];
        while(b < e){
            *b += t;

            if(*b > max_value){
                max_value = *b;
            }

            b++;
        };
        qc++;
        /*
        if(qc%1000==0)
            cout << qc << endl;
            */
    };

    auto time_now = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(time_now - time_prev);
    time_prev = time_now;
    //auto res = max_element(v.begin(), v.end());
    auto duration2 = duration_cast<milliseconds>(high_resolution_clock::now() - time_prev);

    //
    //cout << duration1.count() << ", " << duration2.count() << endl;

    cout << max_value << endl;
        return max_value;
}

int main()
{
    std::filesystem::path cwd = std::filesystem::current_path();
    ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin("ArrayManipulationinput07.txt");
    ofstream fout2("xxxout.txt");
    ofstream fout3("xxxout3.txt");

    // fin.ignore(numeric_limits<streamsize>::max(), '\n');
    string first_multiple_input_temp;
    getline(fin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(fin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));
        if(!queries_row_temp[0].empty()){
            for (int j = 0; j < 3; j++) {
                int queries_row_item = stoi(queries_row_temp[j]);

                queries[i][j] = queries_row_item;
            }
        }
    }
    cout << queries.size() << endl;
    unsigned long qb = (unsigned long)&queries[0];
    unsigned long qe = (unsigned long)&queries[m];
    cout << hex << qb << ".." << qe << " : "  << (qe-qb) << endl << "-----------------------" << endl;
    __parallel::sort(queries.begin(), queries.end()-1, [&](vector<int> a, vector <int> b){
            int average_a = a[0]+(a[0]+a[1])/2;
            int average_b = b[0]+(b[0]+b[1])/2;
            return average_a < average_b;
    });
    for(const vector<int>& q:queries){
        fout2 << q[0] << " " << q[1] << " " << q[2] << endl;
    }
    fout2.close();
    vector<long long> v(n, 0);
    long result = arrayManipulation(n, queries, v);
    for(const int m :v){
        fout3 << m << endl;
    }
    fout2.close();
    

    


    fout << result << "\n";

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
