[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8527364&assignment_repo_type=AssignmentRepo)
# Take-home Assignment 1

## Introduction

In this assignment you will be working on several exercises to get used you to working with
the C programming environment.

- Due: 1 Week
- Deliverables: Commit and push to Github. Submit to Gradescope.

## Assignment Details

There are three parts to this assignment.

Complete the function that you are tasked to complete, and add a description of what the function does (using
Javadoc-style documentation). For example, the `get_max` function from our lecture might have the following
documentation.

    /**
     * Returns the larger of the two
     *
     * @param a The first number
     * @param b The second number
     * @return The larger of the two
     */

Also, starting with this assignment, make sure you commit every time you complete a part, and make sure you write a
description as a commit message.

### Part A

In this part, you will use if/else blocks and simple arithmetic to predict inflation. Every year,
the price of an item will increase by a certain rate. So if the initial cost was 1000, and the inflation
rate was 10% (0.1), then the price would be:

1. After 1 year, 1000 + 1000 * 0.1 = 1100
2. After 2 years, 1100 + 1100 * 0.1 = 1210
3. After 3 years, 1210 + 1210 * 0.1 = 1331

The function definition looks like the following:

    int inflation(int current_price, int num_years, float rate);

It will return the new price that you have computed. Note that the return type is int, so
you need to round the floating point value to an integer value.

For invalid values (such as negative price), return `-1`.

### Part B

In this part, you will be writing some simple functions that use arrays. 

#### Notes on Part B

Sometimes you may see the following message:

    Segmentation fault (core dumped)

Or even this message:

    ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000
        #0 in string_count_upper src/partb.c:5

This is due to the array being NULL. Arrays are essentially pointers to
contiguous elements, and thus may be NULL. To get around this you need check
against this and return an error, like so:

    if(array == NULL) {
        return 0.0;
    }

Sometimes you may also get the following message:

    ERROR: AddressSanitizer: stack-buffer-overflow 
    WRITE of size 4
        #0 in array_fill src/partb.c:20

This means that at line 20, you have an `ArrayIndexOutOfBounds` exception (to use Java speak).

#### Part B.1

For this part, you will implement a function that returns the average over an
array of integers. If the array is invalid (by looking at `array_len`), then
the function should return 0.0.

The function definition looks like the following:

    float array_avg(int *array, int array_len);

`array` points to an integer array of size `array_len`.

#### Part B.2

For this part, you will implement a function that fills the array with numbers,
from `begin` to `end`, in increasing order.

The function definition looks like the following:

    void array_fill(int array[], int array_len, int begin, int end);

For example, after

    array_fill(array, 4, 11, 12);

The array will contain `{11, 12}`.

### Part C

In this part, you will be writing some simple functions that use strings.

**WARNING**: The `<string.h>` header file has similar functions to the ones you will write. You are not allowed to use
those functions, and you will get a 0 for this Part C if you do so!

#### Part C.1

For this part, you will work on a function that counts the number of uppercase
letters in a given string. For example, `"AAaB"` contains 3 uppercase letters.

To work with strings, you need to remember a couple things. First, strings are
essentially `char` arrays, so you work with them as if they were arrays. For example,
to get the first character, you do something like `str[0]`.

Second, instead of using a separate string length variable, C strings have 1
more element that contains the terminating character (`'\0'`) to mark the end
of the string. So, to find the end of a string, you compare it with `'\0'`, like
`str[i] == '\0'`.

To check if a character is uppercase, use the `toupper` function. Search for `manpage toupper`
to see how to use the function.

#### Part C.2

For this part, you will work on a function that concatenates two strings. Concatenation means
there are two strings, and the second string is added to the back of the first string. For example:
"AAA" and "BBB" concatenated becomes "AAABBB".

You will be given a char array that contains a string (and some additional empty space). This is called `dest` for
destination. You will also be given a string that will be concatenated to the first string. After concatenating the
strings, return the `dest` pointer.

Note that because strings are char arrays in C, you *cannot* just do `a + b`. This will not work!

