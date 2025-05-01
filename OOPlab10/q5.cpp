#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Task {
    string text;
    bool done;
};

void addTask(string task) {
    ofstream out("todo.txt", ios::app);
    out << "0|" << task << endl;
    out.close();
}

void viewTasks() {
    ifstream in("todo.txt");
    string line;
    int index = 1;
    while (getline(in, line)) {
        if (line[0] == '1') cout << "[Done] ";
        else cout << "[Todo] ";
        cout << index++ << ". " << line.substr(2) << endl;
    }
    in.close();
}

void markDone(int taskNum) {
    ifstream in("todo.txt");
    ofstream out("temp.txt");
    string line;
    int index = 1;
    while (getline(in, line)) {
        if (index == taskNum && line[0] == '0') line[0] = '1';
        out << line << endl;
        index++;
    }
    in.close();
    out.close();
    remove("todo.txt");
    rename("temp.txt", "todo.txt");
}

int main() {
    int choice;
    while (true) {
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string task;
            getline(cin, task);
            addTask(task);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            int num;
            cin >> num;
            markDone(num);
        } else {
            break;
        }
    }
    return 0;
}
