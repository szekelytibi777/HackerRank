#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Box{
    private:
        long long b;
        long long l;
        long long h;
    public:
    Box(long long _l = 0, long long _b = 0, long long _h= 0)
        : b(_b)
        , l(_l)
        , h(_h)
    {}

    int getLength() const{
        return l;
    }

    int getBreadth() const{
        return b;
    }

    int getHeight() const{
        return h;
    }

    long long CalculateVolume() const{
        long long v = l * b *h;
        return v;
    }

    friend bool operator < (Box& b1, Box& b2)
    {
        if((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
            (b1.l == b2.l && b1.b == b2.b && b1.h <b2.h))
            return(true);
        else
            return(false);
    }

    friend ostream& operator << (ostream& s,Box& b1)
    {
        s << b1.l << " " << b1.b << " " << b1.h;
        return s;
    }
};



int main() {
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }
    }
}