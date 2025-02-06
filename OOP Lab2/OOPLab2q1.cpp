#include <iostream>
#include <cstdlib> 
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) { 
        cout << "Usage: " << argv[0] << " num1 num2 num3 " << endl;
        return 1; 
    }

    int size = argc - 1; 
    int arr[size];
    int* p = arr; 
    int sum = 0;

    
    for (int i = 1; i < argc; i++) {
        *(p + (i - 1)) = atoi(argv[i]); 
        sum += *(p + (i - 1)); 
    }

    cout << "Sum of array elements: " << sum << endl;
    return 0;
}

