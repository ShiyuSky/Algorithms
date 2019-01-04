Implementation for algorithms and data structures


## Dynamic Programming

DP is an algorithmic paradigm that solves a given complex problem by breaking it into overlapping subproblems and stores the result of subproblems to avoid repeating computation. Two main properties of a problem suggest that it can be solved using DP:

(1) overlapping subproblems

(2) optimal substructure: optimal solution of given problem can be obtained by using optimal solutions of its subproblems.

**Longest Increasing Subsequence**:

Note that this is an O(n^2) solution and there is a O(nlogn) solution not using DP.

**Longest Increasing Subsequence**:

O(mn) solution where m and n are the lengths of two sequences respectively.

**0-1 Knapsack**:

Complexity O(nW).


## Sorting

Each sorting algorithms has its beauty. No matter how bad its average or worst case time complexity are, they are still useful in practice.

**Radixsort**:

The lower bound for comparison-based algos is Omega(nlogn). Radix sort improves counting sort, which is a linear time sorting algo that sort in O(n+k) if numbers range from 1 to k, by using counting sort as a subroutine, to achieve better performance when numbers have a larger range. However, it is worse than quicksort in many situations for reasons. It has a large hidden constant factor in the asymptotic runtime. Also, counting sort, as a subroutine, takes extra space to operate.

**Heapsort**:

Heapsort consists of two steps: build the heap and extract the root from the heap n times. Time complexity of the former step is O(n), and latter step is O(nlogn). Heapsort performs worse than quicksort and mergesort in practice, but the heap structure itself has many applications.

**Quicksort**:

Although worst case runtime is O(n^2), which is worse than many other sorting algorithms, the worst case rarely occurs in real world. Its average case runtime is O(nlogn), which can be achieved by carefully selecting the pivot. It is also tail recursive, therefore optimization can be applied.

**Mergesort**:

Time Complexity of mergesort is O(nlogn) for all three cases (worst, average, and best). It requires O(n) extra space when sorting arrays. However, for sorting linked lists, it is particularly useful because we can insert elements in the middle in O(1) space and O(1) time. Therefore merge operations will not require O(n) extra space any more.

**Insertionsort**:

It takes O(n^2) in both worst and average cases, but it takes O(n) in best case. So it is used when only a few elements are misplaced. The lookback loop can be optimized using binary search.

**Selectionsort**:

Always O(n^2) but the number of swaps (memory write) is O(n). It is often used when memory writing operations are expensive (e.g. flash memory) or when sorting large amount of small-sized arrays because asymptotically it is faster than O(nlogn) alternatives.

**Countingsort**:

Time complexity is O(n+k) where n is the number of elements and k is the range of the input. It is not a comparison-based sorting algorithm, so it is possible to sort in linear time when the range k is not significantly greater than number of elements n.

**Bubblesort**:

Worst/average case O(n^2) and best case O(n). In practice, it is often used for sorting almost-sorted arrays in linear time.

## Others

**Floyd's Cycle Detection**:

Detect cycles in singly-linked list in linear time (fastest) and with constant space.

**Run Length Encoding**:

A simple form of lossless data compression method that is useful for data that contains many consecutive values (e.g. AAAAAABBBBBBBCCCCCC).

## Good Practices

**Heap Quiz**: https://www.geeksforgeeks.org/data-structure-gq/heap-gq/

## Reference

[1] GeeksforGeeks
