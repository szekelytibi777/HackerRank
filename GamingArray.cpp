#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <typeinfo>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
typedef long long DataType;

/*
 * Complete the 'gamingArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int index_of_max_element(vector<DataType> arr, map<int, int>& accelerator, int last_index = -1)
{
    if(last_index < 0)
        last_index = arr.size() - 1;
    DataType max_value = INT_MIN;;
    int ret = -1;
    DataType *b = &arr[0];
    DataType *e = &arr[last_index];
    for(DataType *p = b; p <= e; p++){
        if(*p > max_value){
            max_value = *p;
            ret = p-b;
        }
    }
    return ret;
}

template <typename T> bool sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

bool build_accelarator(const vector<DataType>& arr, map<int, int>& accelerator_map)
{
    int index = 0;
    DataType prev = arr[0];
    DataType prev_diff = 0;
    bool ret = true;
    for(const DataType& val: arr){
        DataType diff = val - prev;
        if(val < prev)
            ret = false;
        index++;
    }
    return ret;
}
/**
 * @brief 
 * 
 * @param arr 
 * @return string 
 */
string gamingArray(vector<DataType> arr) {
    bool flag = false;
    string player = "ANDY";
    map<int, int> accel_map;
    bool monotonically_increasing = build_accelarator(arr, accel_map);


    int index = 0;
    if(monotonically_increasing && arr.size() > 1000){
        int siz = arr.size();
        if(siz % 2 == 0)
            player = "ANDY";
        else
            player = "BOB";
        return player;
    }
    else{
        do {
            index = index_of_max_element(arr, accel_map, index-1);
            if(index == -1)
                break;

            if(player == "ANDY") 
                player = "BOB";
            else 
                player = "ANDY";

        } while(index > 0);
    }

    return player;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream fout(getenv("OUTPUT_PATH"));
    //ifstream cin("GamingArrayinput09.txt");
    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<DataType> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            DataType arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        

        string result = gamingArray(arr);

        cout << result << " " << endl;
        fout << result << "\n";
    }

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
