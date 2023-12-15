#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Student{
    private:
        int exam_scores[5];
    public:
        void input(){
            cin >> exam_scores[0];
            cin >> exam_scores[1];
            cin >> exam_scores[2];
            cin >> exam_scores[3];
            cin >> exam_scores[4];
        };

        int calculateTotalScore(){
            int total_score = 0;
            for(int score : exam_scores){
                total_score += score;
            }
            return total_score;
        };
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<Student> students(n);
    for(int i = 0; i < n; i++){
        students[i].input();
    }
    int score_of_kristen = students[0].calculateTotalScore();
    int number_of_scores_higher_than_her = 0;
    for(vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
        int score_of_student = (*it).calculateTotalScore();
        if(score_of_student > score_of_kristen)
            number_of_scores_higher_than_her++;
    }
    cout << number_of_scores_higher_than_her << endl;
    return 0;
}   