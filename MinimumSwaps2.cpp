#include <bits/stdc++.h>
//#include <gperftools/profiler.h>

using namespace std;

vector<string> split_string(string);

template <typename T>
bool is_sorted(const vector<T>& vec, int &index_of_exception)
{
    bool result = true;
    for(int i = 0; i < vec.size()-1; i++)
    {
        if(vec[i-1] != i)
        {
            result = false;
            index_of_exception = i;
            break;
        }
    }
    return result;
}// Complete the minimumSwaps function below.

vector<int> swap(const vector<int>& arr, int i){
    int i1 = i+1;
    vector<int> res(arr);
    res[i] = arr[i1];
    res[i1] = arr[i];
    return res;
}
int num_swaps = 0;
vector<int> sorted(0);

void requrse_swap(int index_of_exception = -1){
   
    if(index_of_exception >= 0){
        int i0 = sorted[index_of_exception -1] -1;
        int i1 = index_of_exception -1;
        int t = sorted[i0];
        sorted[i0] = sorted[i1];
        sorted[i1] = t;
        num_swaps++;
    }
    if(!is_sorted(sorted, index_of_exception))
        requrse_swap(index_of_exception);
}

string to_string(const vector<int>& arr){
    stringstream ss;
    for (const int e:arr){
        ss << e << " ";
    }
    return ss.str();
}

void minimumSwaps(vector<int> arr) {
    //ProfilerStart("prof.prof");
    int index_of_exception = -1;
    requrse_swap(index_of_exception);
    //ProfilerStop();
    //cout << "[" << num_swaps << "] " /*<< to_string(sorted)*/ << endl;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    //ifstream fin("MinimumSwapsinput09.txt");

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }
    sorted = arr;

    minimumSwaps(arr);

    fout << num_swaps << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
