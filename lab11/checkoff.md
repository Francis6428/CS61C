# Exercise 1

* Four floating point divisions in single precision: `__m128 _mm_div_ps (__m128 a, __m128 b)`
* Sixteen max operations over signed 8-bit integers `__m128i _mm_max_epi8 (__m128i a, __m128i b)`
* Arithmetic shift right of eight signed 16-bit integers `__m128i _mm_sra_epi16 (__m128i a, __m128i count)`

# Exercise 2

Let's generate a randomized array.
Starting randomized sum.
Time taken: 24.868195 s
Sum: 412646965248
Starting randomized unrolled sum.
Time taken: 20.298824 s
Sum: 412646965248
Starting randomized SIMD sum.
Time taken: 6.009215 s
Sum: 412646965248
Starting randomized SIMD unrolled sum.
Time taken: 4.820170 s
Sum: 412646965248

```c
long long int sum_simd(unsigned int vals[NUM_ELEMS]) {
	clock_t start = clock();
	__m128i _127 = _mm_set1_epi32(127);		// This is a vector with 127s in it... Why might you need this?
	long long int result = 0;				// This is where you should put your final result!
											// DO NOT DO NOT DO NOT DO NOT WRITE ANYTHING ABOVE THIS LINE.
	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		/* YOUR CODE GOES HERE */
		__m128i values = _mm_setzero_si128();
		for(unsigned int i = 0; i < NUM_ELEMS / 4 * 4; i += 4) {
			__m128i data = _mm_loadu_si128((__m128i*) (vals + i));
			__m128i mask = _mm_cmpgt_epi32(data, _127);
			data = _mm_and_si128(data, mask);
			values = _mm_add_epi32(data, values);
		}
		int arr[4] = {0, 0, 0, 0};
		_mm_storeu_si128((__m128i*) arr, values);
		for (int i = 0; i < 4; ++i) {
			result += arr[i];
		}
		/* You'll need a tail case. */
		for(unsigned int i = NUM_ELEMS / 4 * 4; i < NUM_ELEMS; i++) {
			if (vals[i] >= 128) {
				result += vals[i];
			}
		}
	}
	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return result;
}
```

# Exercise 3

```c
long long int sum_simd_unrolled(unsigned int vals[NUM_ELEMS]) {
	clock_t start = clock();
	__m128i _127 = _mm_set1_epi32(127);
	long long int result = 0;
	for(unsigned int w = 0; w < OUTER_ITERATIONS; w++) {
		/* COPY AND PASTE YOUR sum_simd() HERE */
        /* MODIFY IT BY UNROLLING IT */
        __m128i values = _mm_setzero_si128();
		for(unsigned int i = 0; i < NUM_ELEMS / 16 * 16; i += 16) {
			__m128i data1 = _mm_loadu_si128((__m128i*) (vals + i + 0));
			__m128i data2 = _mm_loadu_si128((__m128i*) (vals + i + 4));
			__m128i data3 = _mm_loadu_si128((__m128i*) (vals + i + 8));
			__m128i data4 = _mm_loadu_si128((__m128i*) (vals + i + 12));
			__m128i mask1 = _mm_cmpgt_epi32(data1, _127);
			__m128i mask2 = _mm_cmpgt_epi32(data2, _127);
			__m128i mask3 = _mm_cmpgt_epi32(data3, _127);
			__m128i mask4 = _mm_cmpgt_epi32(data4, _127);
			data1 = _mm_and_si128(data1, mask1);
			data2 = _mm_and_si128(data2, mask2);
			data3 = _mm_and_si128(data3, mask3);
			data4 = _mm_and_si128(data4, mask4);
			values = _mm_add_epi32(data1, values);
			values = _mm_add_epi32(data2, values);
			values = _mm_add_epi32(data3, values);
			values = _mm_add_epi32(data4, values);
		}
		/* You'll need 1 or maybe 2 tail cases here. */
		for (unsigned int i = NUM_ELEMS / 16 * 16; i < NUM_ELEMS / 4 * 4; i += 4) {
			__m128i data = _mm_loadu_si128((__m128i*) (vals + i));
			__m128i mask = _mm_cmpgt_epi32(data, _127);
			data = _mm_and_si128(data, mask);
			values = _mm_add_epi32(data, values);
		}
		int arr[4] = {0, 0, 0, 0};
		_mm_storeu_si128((__m128i*) arr, values);
		for (int i = 0; i < 4; ++i) {
			result += arr[i];
		}
		/* You'll need a tail case. */
		for(unsigned int i = NUM_ELEMS / 4 * 4; i < NUM_ELEMS; i++) {
			if (vals[i] >= 128) {
				result += vals[i];
			}
		}
	}
	clock_t end = clock();
	printf("Time taken: %Lf s\n", (long double)(end - start) / CLOCKS_PER_SEC);
	return result;
}
```

# Exercise 4

Each time the number sequence is different. 

# Exercise 5

