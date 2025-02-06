#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int id;
    string name;
};

bool compareById(const Person &a, const Person &b) {
    return a.id < b.id;
}

bool compareByName(const Person &a, const Person &b) {
    return a.name < b.name;
}

int main() {
    int N;
    cout << "Enter number of structures: ";
    cin >> N;
    
    vector<Person> people(N);
    
    for (int i = 0; i < N; i++) {
        cout << "Enter ID and Name for person " << i+1 << ": ";
        cin >> people[i].id;
        cin.ignore();
        getline(cin, people[i].name);
    }
    
    sort(people.begin(), people.end(), compareById);
    cout << "Sorted by ID:" << endl;
    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }
    
    sort(people.begin(), people.end(), compareByName);
    cout << "Sorted by Name:" << endl;
    for (int i = 0; i < N; i++) {
        cout << people[i].id << " " << people[i].name << endl;
    }
    
    return 0;
}

