#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    int N, M;
    cout << "Enter number of students: ";
    cin >> N;
    
    vector<Student> students(N);
    
    for (int i = 0; i < N; i++) {
        cout << "Enter ID for student " << i+1 << ": ";
        cin >> students[i].id;
        
        cout << "Enter number of subjects for student " << i+1 << ": ";
        cin >> M;
        
        students[i].subjects.resize(M);
        for (int j = 0; j < M; j++) {
            cout << "Enter subject " << j+1 << " for student " << i+1 << ": ";
            cin.ignore();
            getline(cin, students[i].subjects[j].subject_name);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << "Student ID: " << students[i].id << endl;
        cout << "Subjects: ";
        for (int j = 0; j < students[i].subjects.size(); j++) {
            cout << students[i].subjects[j].subject_name << " ";
        }
        cout << endl;
    }
    
    return 0;
}

