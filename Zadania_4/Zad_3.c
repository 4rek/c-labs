#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdbool.h>

// Funkcja pomocnicza do zamiany dwóch elementów w tablicy miejscami.
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Funkcja sprawdzająca, czy zamiana dwóch elementów jest dozwolona.
bool shouldSwap(int arr[], int start, int curr) {
    for (int i = start; i < curr; i++) {
        if (arr[i] == arr[curr]) {
            return false; // Znaleziono powtórzenie, zamiana nie jest dozwolona.
        }
    }
    return true; // Brak powtórzeń, zamiana jest dozwolona.
}

// Główna funkcja rekurencyjna do generowania permutacji.
void permute(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Sprawdzenie, czy zamiana jest dozwolona, aby uniknąć powtarzania permutacji.
            if (shouldSwap(arr, start, i)) {
                swap(&arr[start], &arr[i]);
                permute(arr, start + 1, end);
                swap(&arr[start], &arr[i]); // Backtrack
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Przykładowy ciąg
    int n = sizeof(arr) / sizeof(arr[0]);
    permute(arr, 0, n - 1);
    return 0;
}

