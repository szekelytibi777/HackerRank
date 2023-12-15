#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    vector<string> parts; 
    char *token = strtok(const_cast<char*>(s.c_str()), ":");
    while (token != nullptr)
    {
        parts.push_back(std::string(token));
        token = strtok(nullptr, ":");
    }
    bool is_afternoon = parts[2][2] == 'P'; 
    parts[2].erase(2, 2);
    int hours = stoi(parts[0]);
    if(is_afternoon){
        if(hours != 12)
            hours += 12;
    }
    else {
        if (hours == 12)
            hours = 0;
    } 
    parts[0] = to_string(hours);
    stringstream ss;
    ss << std::setw(2) << std::setfill('0') << parts[0] << ':' << parts[1] << ':' << parts[2];
    //cout << ss.str();
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
