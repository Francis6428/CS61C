#include <stdlib.h>
#include <omp.h>

#define ARR_SIZE 1024

// When lock is 0, it is free to be acquired.
// Otherwise, someone has the lock.
int lock = 0;

int *build_array() {
    int A[32];
    int B[32];
    for (int i = 0; i < 32; i++) {
        A[i] = rand();
        B[i] = rand();
    }

    int *arr = malloc(sizeof(int) * ARR_SIZE);
    // Analyze the hit rate for the following for loop
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = A[i / 32] + B[i % 32];
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