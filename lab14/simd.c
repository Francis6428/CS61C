#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(_MSC_VER)
#include <intrin.h>
#elif defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
#include <immintrin.h>
#include <x86intrin.h>
#endif

#define SIZE 100

void print_vec(double *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", vec[i]);
    }
    printf("\n");
}

double *load_from_file(char *filename, int size) {
    double *arr = malloc(sizeof(double) * size);
    FILE *fin = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        fscanf(fin, "%lf ", arr + i);
    }
    fclose(fin);
    return arr;
}

void mat_vec_mul(double *mat, double *vec, double *dest, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            dest[row] += mat[row * size + col] * vec[col];
        }
    }
}

double vec_vec_mul(double *vec1, double *vec2, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

void power_method(double *A, double *b, int size) {
    double new_b[size];
    for (int i = 0; i < 10000; i++) {
        mat_vec_mul(A, b, new_b, size);
        double norm = sqrtf(vec_vec_mul(new_b, new_b, size));
        for (int i = 0; i < size; i++) {
            b[i] = new_b[i] / norm;
        }
        memset(new_b, 0, sizeof(double) * size);
    }
}

void mat_vec_mul_simd(double *mat, double *vec, double *dest, int size) {
    // YOUR CODE HERE
}

double vec_vec_mul_simd(double *vec1, double *vec2, int size) {
    // YOUR CODE HERE
    return 0;
}

void power_method_simd(double *A, double *b, int size) {
    // YOUR CODE HERE
}

double get_eigenvalue(double *A, double *b, int size) {
    double mul[size];
    mat_vec_mul(A, b, mul, size);
    return vec_vec_mul(b, mul, size) / vec_vec_mul(b, b, size);
}

int is_close(double *a, double *b, int size) {
    double total_diff = 0;
    for (int i = 0; i < size; i++) {
        total_diff += fabs(a[i] - b[i]);
    }
    return total_diff < 0.0000000001;
}

int main() {
    double *A = load_from_file("A.txt", SIZE * SIZE);
    double b[SIZE];
    for (int i = 0; i < SIZE; i++) {
        b[i] = 1;
    }
    clock_t start = clock();
    power_method(A, b, SIZE);
    clock_t end = clock();

    printf("NAIVE: The first eigenvalue is: %f\n", get_eigenvalue(A, b, SIZE));
    printf("NAIVE: Time elapsed: %f seconds\n", ((double) end - start) / CLOCKS_PER_SEC);

    double simd_b[SIZE];
    for (int i = 0; i < SIZE; i++) {
        simd_b[i] = 1;
    }
    start = clock();
    power_method_simd(A, simd_b, SIZE);
    end = clock();
    if (is_close(simd_b, b, SIZE)) {
        printf("SIMD: The first eigenvalue is: %f\n", get_eigenvalue(A, simd_b, SIZE));
        printf("SIMD: Time elapsed: %f seconds\n", ((double) end - start) / CLOCKS_PER_SEC);
    } else {
        printf("SIMD version doesn't match the NAIVE version!\n");
    }

    free(A);
}
