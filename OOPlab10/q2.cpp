#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    int id;
    char name[50];
    char designation[50];
    int years;
};

int main() {
    Employee data[3] = {
        {1, "Ali", "Manager", 3},
        {2, "Sara", "Engineer", 1},
        {3, "Ahmed", "Manager", 1}
    };

    ofstream out("emp.txt", ios::binary);
    for (int i = 0; i < 3; i++) {
        out.write((char*)&data[i], sizeof(Employee));
    }
    out.close();

    Employee temp;
    Employee selected[3];
    int count = 0;

    ifstream in("emp.txt", ios::binary);
    while (in.read((char*)&temp, sizeof(Employee))) {
        if (strcmp(temp.designation, "Manager") == 0 && temp.years >= 2) {
            selected[count++] = temp;
        }
    }
    in.close();

    ofstream out2("emp.txt", ios::binary);
    for (int i = 0; i < count; i++) {
        selected[i].id += 10;
        selected[i].years += 1;
        out2.write((char*)&selected[i], sizeof(Employee));
    }
    out2.close();

    return 0;
}
