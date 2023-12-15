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

typedef struct {
    string id;
    const string current(const string& attributeName = ""){
        if(attributeName.empty())
            return id;
        else 
            return id + "~" + attributeName;
    }

    void addTag(const string& newTag){
        if(id != "")
            id += ".";
        id += newTag;
    };

    void popTag(const string &tagId = ""){
        size_t nested_pos = id.rfind('.');
        size_t id_pos = id.rfind(tagId);
        if(!id.empty() && id_pos == string::npos)
            assert(0 && "This member is not part of the hierarchy");
        if(nested_pos == string::npos){
        // Root Tag
            if(id_pos == 0)
                id = "";
        }
        else if(id_pos-nested_pos == 1){
            // Top Nested Tag
            id.erase(nested_pos);
        }
    };
}NestedTagID;

string ltrim(const string &);
string rtrim(const string &);


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, Q;
    cin >> N;
    cin >> Q;
    map<string, string> attributes;
    NestedTagID ntid;

    for(int n=0; n < N; n++){
        string line;
        getline(cin, line);
        while(line == ""){
            getline(cin, line);
        }
        size_t pos_open = line.find("<");
        size_t pos_close = line.find("</");
        string attribute;
        string tag_id;
        if(pos_close == 0){
            size_t apos = line.find(">");
            tag_id = line.substr(2, apos-2);
            ntid.popTag(tag_id);
        }
        else if(pos_open == 0){
            size_t apos = line.find(" ");
            if(apos == string::npos)
                apos = line.find(">");
            tag_id = line.substr(1, apos-1);
            ntid.addTag(tag_id);
            if(apos != string::npos){
                string attribute_assignment = line.substr(apos);
                regex attribute_regexp("(\\w+)\\s?=\\s?\"(.*?)\""); 
                auto iter = sregex_iterator(attribute_assignment.begin(), attribute_assignment.end(), attribute_regexp);
                auto iter_end = sregex_iterator();
               
                while(iter != iter_end){
                    smatch match = *iter;
                    string match_str = match.str();
                    size_t mark_pos = match_str.find("=");
                    string attribute_name, attribute_value;
                    if(mark_pos != string::npos){
                        attribute_name =  ltrim(rtrim(match_str.substr(0, mark_pos)));
                        attribute_value = ltrim(rtrim(match_str.substr(mark_pos+1)));
                        attribute_value.erase(remove(attribute_value.begin(), attribute_value.end(), '\"'), attribute_value.end());
                        attributes[ntid.current(attribute_name)] = attribute_value;
                    }
                    
                    iter++;
                }
            }
        }
        
    }
    vector<string> queries;
    for(int q=0; q < Q; q++){
        string query;
        getline(cin, query);
        while(query == "")
            getline(cin, query);
        queries.push_back(query);
    }

    for(string query : queries){
        if(attributes.count(query))
            cout << attributes[query] << endl;
        else
            cout << "Not Found!" << endl;

    }
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


    