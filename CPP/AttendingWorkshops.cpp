#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct WorkShop{
    int startTime;
    int duration;
    int endTime;
    string to_string(){
        stringstream ss;
        ss << startTime << " - " << endTime <<" (" << duration << ")";
        return ss.str();
    }
};

bool compare_workshops(const WorkShop &ws1, const WorkShop &ws2)
{
    if(ws1.endTime < ws2.endTime)
        return 1;
    return 0;
}

struct AvailableWorkShops{
    int numberOfWorkShops;
    WorkShop* workshops;
    void printWorkshops(){
        for(int i = 0; i < numberOfWorkShops; i++){
            cout << i << ". " << workshops[i].to_string() << endl; 
        }
    }
};

AvailableWorkShops* initialize(int start_time[], int duration[], int n){
    AvailableWorkShops* workshops = new AvailableWorkShops();
    workshops->numberOfWorkShops = n;
    workshops->workshops = new WorkShop[n];
    for(int i = 0; i < n; i++){
        workshops->workshops[i].duration = duration[i];
        workshops->workshops[i].startTime = start_time[i];
        workshops->workshops[i].endTime = start_time[i] + duration[i];
    }
    sort(workshops->workshops, workshops->workshops+n, &compare_workshops);
    cout << "--------------------------" << endl;
    return workshops;
}

int CalculateMaxWorkShops(AvailableWorkShops* ptr, int nw){
    int count = 1;
    int temp_end_time = ptr->workshops[0].endTime;
    for(int i = 1; i < nw; i++){
        if(temp_end_time <= ptr->workshops[i].startTime){
            count++;
            temp_end_time = ptr->workshops[i].endTime;
        }
    }
    return count;
}

bool isOverlaped(WorkShop *ws0, WorkShop *ws1){
    if(ws0->startTime > ws1->endTime)
        return false;
    if(ws1->startTime > ws0->endTime)
        return false;
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int startTimes[n];
    int durations[n];
    for(int i = 0; i < n; i++){
        cin >> startTimes[i];
    }
    for(int i = 0; i < n; i++){
        cin >> durations[i];
    }

    AvailableWorkShops* aws = initialize(startTimes, durations, n);
    int numWorkShops = CalculateMaxWorkShops(aws, n);
    cout << numWorkShops << endl;
    return 0;
}
