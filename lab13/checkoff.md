# Lab 13 Checkoff

## Exercise 1

TLB hits: 4, TLB misses: 6; Page hits: 0, Page faults: 6

There was no page hit.

I don't know how to make the page hit to turn non-zero.

## Exercise 2

`00 20 40 60 80 A0 C0 E0 00 20`

## Exercise 3

We can increase the memory size so that the accesses `00` and `20` won't be page faults.

## Exercise 4

Explanations:

* `P1 P2 P3 P4` denotes two different processes.
* The high miss rate is caused by alternation between process. Each process has a separate page table and a different TLB, making the accesses very likely to miss.
