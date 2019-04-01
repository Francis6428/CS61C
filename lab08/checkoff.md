# Exercise 1

## Scenario 1

### What combination of parameters is producing the hit rate you observe?

hit rate 0, the step size is the same as the block size. 

### What is our hit rate if we increase Rep Count arbitrarily? Why?

It remains unchanged because each time there a new block will be pulled. 

### How could we modify one program parameter to increase our hit rate?

Change option to 1. 0.5

## Scenario 2

### How many memory accesses are there per iteration of the inner loop? (not the one involving repcount). It’s not 1.

2 for the same block

### What is the repeating hit/miss pattern? WHY? (Hint: it repeats every 4 accesses).

M H H H

### Explain the hit rate in terms of the hit/miss pattern.

0.75

### Keeping everything else the same, what happens to our hit rate as Rep Count goes to infinity? Why?

Approaches 1, because the cache can contain the whole array. 

## Scenario 3

### What is the hit rate of our L1 cache? Our L2 cache? Overall?

L1: 0.5, L2: 0

### How many accesses do we have to the L1 cache total? How many of them are misses?

32 16

### How many accesses do we have to the L2 cache total? How does this relate to the L1 cache

16, same number of L1 misses

### What program parameter would allow us to increase our L2 hit rate, but keep our L1 hit rate  the same? Why?

rep count, since L2 is larger and not filled if there is one cycle.

### What happens to our hit rates for L1 and L2 as we slowly increase the number of blocks in L1? What about L1 block size?

increasing the number of blocks in L1: remains the same 0. 

increasing the block size of L1: L1 increase, L2 remains to be 0

# Exercise 2

## Which ordering(s) perform best for these 1000-by-1000 matrices? Why?

jki works the best because it moves through B with stride 0, A with stride 1, C with stride 1

## Which ordering(s) perform the worst? Why?

ikj kij. this is because it moves through B and C with stride n and A with stride 0. The huge strides in B,C causes the underperformance. 

## How does the way we stride through the matrices with respect to the innermost loop affect performance?

The less stride, the better performance. 

# Exercise 3

