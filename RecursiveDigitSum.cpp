#include <bits/stdc++.h>

using namespace std;
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

string recurse(string n){
    unsigned long long offs = n.size()*'0';
    unsigned long long result = accumulate(n.begin(), n.end(), 0L);
    unsigned long long d = result-offs;

    string ret = to_string(d);
    //cout << ret << endl;
    if(ret.size()>1)
        ret = recurse(ret);

    return ret;
}
//#define TEST "RecurseDigitSuminput07.txt"
#ifdef TEST
    #define CIN fin
#else
    #define CIN cin
#endif
unsigned long long superDigit(string n, int k=-1) {
    #ifdef TEST
        auto start_time = chrono::high_resolution_clock::now();
    #endif
    //size_t r = n.size()*k;
    string digits;
    //digits.reserve(r);
    unsigned long long ret = 0;
    stringstream ss(digits);
    fill_n(ostream_iterator<string>(ss), k, n);
    string s;
    //string_view sv(ss.str());
    s = recurse(ss.str());
    ret = stoull(s);
   
    #ifdef TEST
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        cout << s << " " << duration.count() << endl;
    #endif

    return ret;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    #ifdef TEST
    ifstream fin(TEST);
    #endif
    string first_multiple_input_temp;

    char c;    
    getline(cin, first_multiple_input_temp);
    

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;
    vector<char> charvec(str.begin(), str.end());

    auto f = count(charvec.begin(), charvec.end(), ' ');
    string token = str.substr(0, str.find(" ", 0));
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
