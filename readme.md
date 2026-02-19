Findlines
=========

A small C program that prints lines from standard input which contain a given search query. The program aims to behave like a minimal substring version of grep when reading from stdin

## Learning Outcomes

After completing this lab learners will be able to

1. Replace a static buffer with heap allocation and manage memory safely
2. Read text input line by line using standard C I/O functions
3. Describe trade offs in memory usage and thread safety

## Usage

Build the binary with make:

```sh
make
```

Pipe data to the program to search for text:

```sh
> cat belgic-confession.md | ./findlines Jesus
We distinguish between these holy books and the apocryphal ones, which are the third and fourth books of Esdras; the books of Tobit, Judith, Wisdom, Jesus Sirach, Baruch; what was added to the Story of Esther; the Song of the Three Children in the Furnace; the Story of Susannah; the Story of Bell and the Dragon; the Prayer of Manasseh; and the two books of Maccabees.
And in another place it says: "The grace of our Lord Jesus Christ, and the love of God, and the fellowship of the Holy Spirit be with you."
...
```

The program prints each line that contains the substring provided as the single command line argument

## Testing

Run the included test using make test

```
make test
```

The test builds the program and compares the program output for the example file with the expected output file

## Tasks

1. Replace the global static buffer with a heap allocation that initially reserves 100 bytes
2. Detect when a line does not fit the current allocation and reallocate a larger buffer to hold the full line
3. Ensure every allocation is freed before the function returns so the function does not leak memory
4. Preserve existing behavior that prints matching lines and otherwise exits normally
5. Add comments and tests if necessary to demonstrate correctness

## Resources

- [fgets](https://en.cppreference.com/w/c/io/fgets) manual page and examples
- [malloc and free](https://en.cppreference.com/w/c/memory/malloc) reference
- [strstr](https://en.cppreference.com/w/c/string/byte/strstr) reference
- [strchr](https://en.cppreference.com/w/c/string/byte/strchr) reference
- [buffer overflow](https://en.wikipedia.org/wiki/Buffer_overflow) notes on buffer management and reallocation strategies
