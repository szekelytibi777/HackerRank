#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <regex>
#include <string> 
#include <cassert>
using namespace std;

int main(){
    //string mystr = "<tag3 another=\"another\" final=\"final\">";
    string s2 = "<tag1 value=\"HelloWorld\">";
    string s = "<tag3 another=\"another\" final=\"final\">";
    regex str_regexp ("(\\w+)\\s?=\\s?\"(.*?)\""); 
    auto words_iter = std::sregex_iterator(s.begin(), s.end(), str_regexp);
    auto words_end = std::sregex_iterator();
    cout << "Found " << distance(words_iter, words_end) << " words\n";
    smatch m;
    regex_match(s, m, str_regexp);

    while(words_iter != words_end){
        smatch match = *words_iter;
        string match_str = match.str();
        cout << match_str << endl;
        words_iter++;
    }

    
 /*
    // flag type for determining the matching behavior (in this case on string objects)
    cmatch cm;
    regex_match (mystr,cm,str_expr); 
    // regex_search that searches pattern regexp in the string mystr  
    for (auto x : cm) 
        cout << x << " ";      
        */
}