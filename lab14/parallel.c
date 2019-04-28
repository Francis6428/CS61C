#include <stdlib.h>
#include <omp.h>

#define ARR_SIZE 10000

// When lock is 0, it is free to be acquired.
// Otherwise, someone has the lock.
int lock = 0;

int *build_array() {
    int A[100];
    int B[100];
    for (int i = 0; i < 100; i++) {
        A[i] = rand();
        B[i] = rand();
    }

    int *arr = malloc(sizeof(int) * ARR_SIZE);
    // Analyze the hit rate for the following for loop
    for (int i = 0; i < 10000; i++) {
        arr[i] = A[i / 100] + B[i % 100];
    }

    return arr;
}

int main() {
    int *arr = build_array();

    long long int sum = 0;
    int partial_sum = 0;
    int i = 0;
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < ARR_SIZE; i++) {
            partial_sum += arr[i];
        }

        // Critical section
        while (lock != 0);  // Wait until lock is free
        lock++;             // Acquire lock
        sum += partial_sum;
        lock--;             // Release lock
    }

    free(arr);
    return 0;
}