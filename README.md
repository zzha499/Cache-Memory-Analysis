# Cache-Memory-Analysis

Task 1 is to write a short C program that measures the access time differences of the caches in your system. To
perform the measurement write a short program that consists of a loop with N iterations over an integer array a
of size N, where you sum the value of each element of a. The execution of this loop is repeated M times, where M
needs to be a large number. Measure the time it takes to execute this and divide by the total number of iterations,
i.e. M x N, to get the time per iteration. Repeat this measurement for many different sizes of N (also changing
the size of the array a), ranging from smaller than half the L1 cache to much bigger than L3 cache. Do these
measurements in two different ways:

  1. Go linearly through the array a
  2. Go randomly through the array a
  
To achieve the two different ways and have a fair comparison, use a helper array b which you initialise with values
from 0 to N-1 in order. Use b as the index for array a, i.e. a[b[i]]. For case 1 you use b directly after initialising,
in case 2 you first shuffle the values. Do this by randomly choosing two elements of b (using rand()) and swap
their values. Repeat this swapping at least N times.

Task 2 Your task is to write a short C program that measures the time to perform the product of two N x N-size matrices
A and B, C = AB. 
  1. Write a straight forward implementation of this matrix product. Measure and document the time it takes in
     your pdf. Identify what the problematic access pattern is in this implementation.
  2. Write a new implementation where you solve this problem by using a temporary matrix (hint: transpose one
     matrix). Measure and document the time it takes in your pdf. Include the creation of the temporary matrix
     in your time measurement.
  3. For large matrices it might not be possible to have a temporary matrix copy due to memory size. Anyway,
     we can do even better. Based on the original approach, use blocking, that is process k x k blocks at a time.
     (Hint: k should relate to the cache line size). Write an implementation based on blocking. Measure and
     document the time it takes in your pdf. Explain your approach briefly. (Hint: it might not be easy to get a
     good improvement, an in-principle-correct attempt will be considered good enough.)
