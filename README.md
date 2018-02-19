Asst1: To Buld A Better Malloc
CS 214: Systems Programming, Spring 2018

Design
======
For this assignment, our implementation of mymalloc and myfree functions simulate what occurs in memory for the malloc() and free() library calls.  The usage of a linked list to allowed for us to keep information of memory blocks including, whether or not a block of memory is free, the size of an allocated block, and the next block in memory that it points to.  Using a linked list allowed for easy creation of memory blocks with the small sacrifice of space that was the size of the struct itself.  

Difficulties & Testing
=======================
Because of the many ways that these functions can be implemented, there are many areas where things can go wrong.  A few issues that we had to deal with was segmentation faults when trying to allocate certain sizes of memory and having to fix a bug where after allocating a large chuck of memory (ex: 1000), and allocating something afterwards caused the program to not continue.  A reevaluation of our mymalloc() function allowed us to fix this bug and get the program to work.

Workload Data & Findings
=========================
With 6 workloads, the program appears to run anywere between 0.003804 seconds and 0.019354 seconds per iteration.  Workloads 1 and 2 seem to work as intended, successfully allocating and freeing all memory locations.  Workloads 3 and 4 seem to behave unordinarily as they don't appear to work together.  Workload 3 can only work separately from workload 4.  In regard to workloads 5 and 6, they compile and seem to allocate memory correctly, however don't always free the pointers when needed.
