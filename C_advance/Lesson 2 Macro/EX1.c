#include <stdio.h>

#define PRINT_ARRAY(...)                \
    do {                                \
        printf("Array elements: ");     \
        printf(__VA_ARGS__);            \
        printf("\n");                   \
    } while(0)

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    // Sử dụng macro PRINT_ARRAY để in các phần tử trong mảng
    PRINT_ARRAY("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);

    return 0;
}
