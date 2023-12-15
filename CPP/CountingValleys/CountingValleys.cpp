#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int height_above_see_level = 0;
    int height_above_see_level_of_previous_step = 0;
    int valley_count = 0;
    for(const char step: path)
    {

        if(step == 'U')
            height_above_see_level++;
        else if (step == 'D')
            height_above_see_level--;
        if(height_above_see_level_of_previous_step == 0 && height_above_see_level < 0)
            valley_count++;
        height_above_see_level_of_previous_step = height_above_see_level;

    }
    return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    string ret;
    if (start == std::string::npos)
        ret = "";
    else
        ret = s.substr(start);
    return ret;
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    string ret;
    if (end == std::string::npos)
        ret = "";
    else
        ret = s.substr(0, end + 1);

    return ret;
}
