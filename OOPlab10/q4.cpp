#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void rotateLogs(int &logNumber) {
    string oldName = "log.txt";
    string newName = "log" + to_string(logNumber++) + ".txt";
    rename(oldName.c_str(), newName.c_str());
}

int getFileSize(const char* filename) {
    ifstream in(filename, ios::binary | ios::ate);
    return in.tellg();
}

int main() {
    int logNumber = 1;
    string message;
    while (getline(cin, message)) {
        if (getFileSize("log.txt") > 1024 * 1024) {
            rotateLogs(logNumber);
        }
        ofstream out("log.txt", ios::app);
        out << message << endl;
        out.close();
    }
    return 0;
}
