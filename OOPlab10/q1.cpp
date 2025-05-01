#include <iostream>
#include <fstream>
using namespace std;

string encrypt(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] + (i + 1);
    }
    return text;
}

string decrypt(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] - (i + 1);
    }
    return text;
}

int main() {
    string input;
    getline(cin, input);
    string encrypted = encrypt(input);
    ofstream out("data.txt");
    out << encrypted;
    out.close();

    ifstream in("data.txt");
    string fileData;
    getline(in, fileData);
    in.close();
    string decrypted = decrypt(fileData);

    cout << "Normal Text:= " << input << endl;
    cout << "Encrypted text inserted in file\n";
    cout << fileData << endl;
    cout << "Decrypted text Read then decoded from file\n";
    cout << decrypted << endl;
    return 0;
}
