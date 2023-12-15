
    // #include <cstdio>
    #include <iostream>
    #include <string>
    #include <fstream>
    using namespace std;

    int start_up() { ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }
    int static r = start_up();

    template <class T>
    class AddElements {
        T element;
    public:
        AddElements (T arg) {element=arg;}
        T add (T x) {return x+element;}
    };

    template <>
    class AddElements <string> {
        string element;
    public:
        AddElements (string arg) {element=arg;}
        string concatenate (string arg)
        {
        string s = element+arg;
        return s;
        }
    };
    #define TEST 0

    #if TEST 
        #define CIN ifs
    #else
        #define CIN cin
    #endif

    #define COUT cout

    int main() {
        ifstream ifs("ClassTrmplateinput01.txt");
        ofstream ofs("output01.txt");
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
        int N;
        CIN >> N;
        while(N--){
            string t;
            string a, b;
            CIN >> t;
            if(t == "string"){
                CIN >> a >> b;
                AddElements<string> ms(a);
                COUT << ms.concatenate(b) << "\n";
            }
            else if (t == "int"){
                int i1; 
                int i2;
                CIN >> i1 >> i2;
                AddElements<int> mi (i1);
                COUT << mi.add(i2) << "\n";
            }
            else if (t == "float"){
                float f1; 
                float f2; 
                CIN >> f1 >> f2;
                AddElements<float> mt(f1);
                COUT << mt.add(f2) << "\n";
            }
        }
        return 0;
    }
