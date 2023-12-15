#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int number_of_elements = arr.size();
    int number_of_positives = 0;
    int number_of_negatives = 0;
    int number_of_zeros = 0;
    for(int element: arr){
        if (element > 0)
            number_of_positives++;
        else if (element < 0)
            number_of_negatives++;
        else
            number_of_zeros++;
    }
    float ratio_positives = (float)number_of_positives / (float)number_of_elements;
    float ratio_negatives = (float)number_of_negatives / (float)number_of_elements;
    float ratio_zeros = (float)number_of_zeros / (float)number_of_elements;
    printf("%.6f\n", ratio_positives);
    printf("%.6f\n", ratio_negatives);
    printf("%.6f\n", ratio_zeros);
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
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
