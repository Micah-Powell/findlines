Findlines
=========

A small C program that prints lines from standard input which contain a given search query. The program aims to behave like a minimal substring version of grep when reading from stdin

## Learning Outcomes

After completing this lab learners will be able to

1. Replace a static buffer with heap allocation and manage memory safely
2. Read text input line by line using standard C I/O functions
3. Describe trade offs in memory usage and thread safety

This program currently allocates a single, static, global buffer for processing lines. This presents a number of limitations:

- The search function will fail to properly process lines containing more than 1000 characters.
- The search function uses extra memory for files with only short lines.
- The search function is not thread safe. The program could not be extended to search multiple files simultaneously using this implementation.

You will modify the program to use a heap allocation with the following properties:

- An initial allocation of 100 bytes will be used.
- If a line is encountered that exceeds this space, a new larger space should be allocated and used instead.
- The lifetime of this heap space should not extend beyond the function invocation. All memory allocated by the function must be freed before the function returns.
