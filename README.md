Implementation for algorithms and data structures

## Sorting

**Quicksort**:

Although worst case runtime is O(n^2), which is worse than many other sorting algorithms, the worst case rarely occurs in real world. Its average case runtime is O(nlogn), which can be achieved by carefully selecting the pivot. It is also tail recursive, therefore optimization can be applied.

**Mergesort**:

Time Complexity of mergesort is O(nlogn) for all three cases (worst, average, and best). It requires O(n) extra space when sorting arrays. However, for sorting linked lists, it is particularly useful because we can insert elements in the middle in O(1) space and O(1) time. Therefore merge operations will not require O(n) extra space any more.

**Insertionsort**:

It takes O(n^2) in both worst and average cases, but it takes O(n) in best case. So it is used when only a few elements are misplaced. The lookback loop can be optimized using binary search.

## Data Compression

**Run Length Encoding**

## Reference

[1] GeeksforGeeks
