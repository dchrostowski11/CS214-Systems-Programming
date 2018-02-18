Asst1: To Buld A Better Malloc
CS 214: Systems Programming, Spring 2018

Design
======
For this assignment, our implementation of mymalloc and myfree functions simulate what occurs in memory for the malloc() and free() library calls.  The usage of a linked list to allowed for us to keep information of memory blocks including, whether or not a block of memory is free, the size of an allocated block, and the next block in memory that it points to.  Using a linked list allowed for easy creation of memory blocks with the small sacrifice of space that was the size of the struct itself.  

Difficulties & Testing
=======================
Because of the many ways that these functions can be implemented, there are many areas where things can go wrong.  A few issues that we had to deal with was segmentation faults when trying to allocate certain sizes of memory and having to fix a bug where after allocating a large chuck of memory (ex: 1000), and allocating something afterwards caused the program to not continue.  A reevaluation of our mymalloc() function allowed us to fix this bug and get the program to work.

Compilation
============
