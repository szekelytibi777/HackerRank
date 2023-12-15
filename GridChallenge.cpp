#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    size_t n = grid.size();
    bool flag = true;
    flag = true;
    for(int i = 0; i < grid.size(); i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    for (int i = 0; i < n; i++){

        for (int j = 0; j + 1 < n; j++) 
            if (grid[j][i] > grid[j+1][i]) 
                flag = false;
    }

	return(flag ? "YES" : "NO");
}
#define TEST 0
#if TEST
    #define CIN fin
    #define COUT cout
#else
    #define CIN cin
    #define COUT fout
#endif

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin("GridChallengeinput02.txt");


    string t_temp;
    getline(CIN, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(CIN, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(CIN, grid_item);

            grid[i] = grid_item;
        }

            string result = gridChallenge(grid);

        COUT << result << "\n";
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
