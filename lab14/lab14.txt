Exercise 1
----------
1. ARR_SIZE isn't stored anywhere in memory since the preprocessor replaces all of its instances in the code with the corresponding value. lock is in the static section of memory.
2. The first thing we notice is that the elements of A and B are accessed repeatedly. For A, we access the same element until i reaches a multiple of 32, after which we go to the next one. For B, we loop through the array over and over again. The "arr" array is larger than the cache, so at some point we will map to the same index in the cache (when i = 64 to be exact, and then every 64 after that). However, if a replacement is necessary, then we won't replace the blocks from A or B that are still in use since they will have been accessed more recently than blocks from arr. As such, blocks from A and B never get replaced.

With this, we see that arr has a repeating MHHH pattern and A and B only have 1 compulsory miss for each of their 8 blocks and no misses after that. Therefore, we have (1/4) * 1024 + 8 + 8 = 272 misses, or 1024 * 3 - 272 = 2800 hits which corresponds to a ~91.1% hit rate.
3. partial_sum is not private so the value might be inconsistent. We could either declare it to be private or declare it inside the parallel block.
4. Suppose we have the following execution order when the lock is 0:

     Thread 1             Thread 2
-------------------  -------------------
 while (lock != 0);
                      while (lock != 0);
 lock++;
 sum += partial_sum;
 lock--;
                      lock++;
                      sum += partial_sum;
                      lock--;

With this ordering, both threads read that the lock had a value of 0 and assumed that they had successfully acquired the lock. This is especially bad here since the += line both reads and updates sum, which could yield to inconsistent values.


Exercise 2
----------
WordDocPair:
    String word
    Document doc

map(Document doc):
    for word in doc.text:
        emit((word, doc), 1)

reduce(WordDocPair k, list<int> values):
    total = 0
    for v in values:
        total += v
    emit((k.word, k.doc.name), total / len(k.doc.text))


Exercise 3
----------
double vec_vec_mul_simd(double *vec1, double *vec2, int size) {
    __m256d intermediate_result = _mm256_set1_pd(0.0);
    for (int i = 0; i < size; i += 4) {
        intermediate_result = _mm256_fmadd_pd(_mm256_loadu_pd(vec1 + i),
                                              _mm256_loadu_pd(vec2 + i),
                                              intermediate_result);
    }
    double result[4];
    _mm256_storeu_pd(result, intermediate_result);
    return result[0] + result[1] + result[2] + result[3];
}

void mat_vec_mul_simd(double *mat, double *vec, double *dest, int size) {
    for (int row = 0; row < size; row++) {
        dest[row] = vec_vec_mul_simd(mat + row * size, vec, size);
    }
}

void power_method_simd(double *A, double *b, int size) {
    double new_b[size];
    for (int i = 0; i < 10000; i++) {
        mat_vec_mul_simd(A, b, new_b, size);
        double norm = sqrtf(vec_vec_mul_simd(new_b, new_b, size));
        for (int i = 0; i < size; i++) {
            b[i] = new_b[i] / norm;
        }
        memset(new_b, 0, sizeof(double) * size);
    }
}