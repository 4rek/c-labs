#include <stdio.h>
#include <stdlib.h>

int find_binary(int arr[], int start, int end, int v) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == v) {
        return mid;
    }
    if (arr[mid] > v) {
        return find_binary(arr, start, mid - 1, v);
    }
    return find_binary(arr, mid + 1, end, v);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Wpisz wyszukiwaną liczbę: \n");
    int input;
    scanf("%d", &input);

    int index = find_binary(arr, 0, size, input);
    if (index != -1) {
        printf("Liczba %d znaleziona na pozycji: %d\n", input, index);
    } else {
        printf("Liczba %d nie została znaleziona w tablicy.\n", input);
    }
}
