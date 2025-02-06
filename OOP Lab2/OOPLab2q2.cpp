#include <iostream>
#include <cstdlib>
using namespace std;

void* addToArray(void* arr, int size, int addValue) {
    int* p = static_cast<int*>(arr);
    for (int i = 0; i < size; i++) {
        *(p + i) += addValue;
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " num1 num2 num3 ..." << endl;
        return 1;
    }

    int size = argc - 1;
    int arr[size];
    int* p = arr;

    for (int i = 1; i < argc; i++) {
        *(p + (i - 1)) = atoi(argv[i]);
    }

    int addValue = 5;
    void* modifiedArray = addToArray(arr, size, addValue);

    cout << "Modified Array: ";
    for (int i = 0; i < size; i++) {
        cout << *(static_cast<int*>(modifiedArray) + i) << " ";
    }
    cout << endl;

    return 0;
}

