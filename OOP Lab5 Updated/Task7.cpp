#include <iostream>

using namespace std;

class Student {
private:
    const int roll_no;

public:
    Student(int roll) : roll_no(roll) {}

    void show() {
        cout << "Roll number is " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter roll number " << endl;
    cin >> roll;
    Student s(roll);
    s.show();
    return 0;
}

