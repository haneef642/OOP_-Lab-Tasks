#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int *arr = (int*)malloc(size * sizeof(int));
    int count = 0;
    
    while (1) {
        int num;
        printf("Enter a number (or -1 to stop): ");
        scanf("%d", &num);
        
        if (num == -1) break;
        
        if (count >= size) {
            size *= 2;
            arr = (int*)realloc(arr, size * sizeof(int));
        }
        
        arr[count++] = num;
    }

    size = count;
    arr = (int*)realloc(arr, size * sizeof(int));

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

