#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
    // part which will store data
    int data;
    // pointer to the previous node
    struct Node *prev;
    // pointer to the next node
    struct Node *next;

    Node(int _data = 0)
        : data(_data)
        , prev(0)
        , next(0){}

    void insert(Node *beforeNode){
        if(beforeNode){
            next = beforeNode;
            prev = beforeNode->prev;
            beforeNode->prev = this;
        }
    }
};

class Cache{
    public:
        int cp;   // capacity of cache
        int cn = 0;         // number of cached values
        map<int, Node*> mp;
        Node *tail = 0;
        Node *head = 0;
        Cache(int capacity)
            : cp(capacity)
        {}

        Node* getLastNodeAndMapNodes(){
            Node *n = head;
            Node *lastNode = 0;
            int count = 0;
            while(n){
                count++;
                if(count < cp)
                    tail = 0;
                else if(count == cp){
                    tail = n;
                    n->next = 0;
                }
                mp[count]=n;

                n = n->next;

            }
            cn = count;
            return lastNode;
        }

        void set(int key, int value){
            if(map.count(key)){
                nn = map[key];
            }
            else{
                map[0] = new Node(value);

            }

            else if(cn == 0)
                Node *n = new Node(value);
                head = n;
                tail = n;
            }
            else if (cn < cp){
                Node *n = 0;
                for(pair<int, Node*>p : mp){
                    // data is in the cache allready
                    if(p.second->data == value){
                        n = p.second;
                        break; 
                    }
                }
                if(!n)
                    n = new Node(value);
                n->insert(head);
                cn=0;
                tail = getLastNodeAndMapNodes();
            }

        }

        int get(int key){
            int c = 0;
            Node *node = head;
            while(node){
                c++;
                if(c == key){
                    return node->data;;
                }
                node = node->next;
            }
            return -1;
        }
};

struct Cmd{
    string cmd;
    int key;
    int value;
    Cmd(string c="", int k=0, int v=-1)
        : cmd(c)
        , key(k)
        , value(v)
        {}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, capacity;
    cin >> n;
    cin >> capacity;
    Cache cache(capacity);
    vector<Cmd> commands;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "set"){
            int key, value;
            cin >> key;
            cin >> value;
            Cmd c(cmd, key, value);
            commands.push_back(c);
        }
        else if(cmd == "get"){
            int key;
            cin >> key;

            Cmd c(cmd, key);
            commands.push_back(c);
        }
    }

    for(Cmd c : commands){
        if(c.cmd == "set"){
            cache.set(c.key, c.value);
        }
        else if(c.cmd == "get"){
            int d = cache.get(c.key);
            cout << d << endl;
        }

    }

    return 0;
}
