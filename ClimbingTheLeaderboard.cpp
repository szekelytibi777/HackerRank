
/*
https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/
#include <bits/stdc++.h>
#define TEST "ClimbingTheLeaderBoard_TestInput_01.txt"
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

string toString(vector<int> &scores){
    stringstream ss;
    ss << "{";
    int c = scores.size();
    for(int &s:scores){
        string dm = --c ? "," : "";
        ss << s << dm;
    }
    ss << "}";
    return ss.str();
}

 template<typename _Tp>
    struct greater_abs : public binary_function<_Tp, _Tp, bool>
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const _Tp& __x, const _Tp& __y) const
      { return abs(__x) > abs(__y); }
    };

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> res;
    for(int player_score: player){
        int rank = 1;
        int prev_score = -1; // uninitialised
        for(int score: ranked){
            if(prev_score == -1 && player_score >= score){
                res.push_back(rank);
                break;
            }
            if(player_score <= prev_score && (player_score >= score || prev_score == -1)){
                prev_score = player_score;
                if(res.back() != rank)
                    res.push_back(rank);
            }
            else if(prev_score != score )
                rank ++;
            prev_score = score;
        }   
        if(res.empty())
            res.push_back(rank);

    }


    return res;
}


#ifdef TEST
    #define CIN fin
#else
    #define CIN cin
#endif
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    #ifdef TEST
    ifstream fin(TEST);
    #endif

    string ranked_count_temp;
    getline(CIN, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(CIN, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(CIN, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(CIN, player_temp_temp);

    vector<string> player_temp= split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
