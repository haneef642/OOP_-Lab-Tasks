#include <iostream>
using namespace std;

int main() {
    string name;
    double score1, score2, score3, score4, score5, average;
     
     cout<<"Enter student name"<<endl;
    cin >> name;
    
    cout<<"Enter 5 test scores"<<endl;
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    average = (score1 + score2 + score3 + score4 + score5) / 5;

    cout << "Student name: " << name << endl;
    cout << "Test scores: " << score1 << " " << score2 << " " << score3 << " " << score4 << " " << score5 << endl;
    cout << "Average test score: " << (int)(average * 100) / 100.0 << endl;

    return 0;
}

