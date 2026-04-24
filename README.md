*This project has been created as part of the 42 curriculum by soyamagu.*

# Description
<font color="Green">**Push swap**</font> is a project that sorts integers using two stacks and a limited set of operations, with the number of instructions as small as possible.

### Brief Summary
The goal of this project is to sort a list of integers in ascending order in stack a by using two stacks (a and b) and a limited set of operations.

The program does not output the sorted numbers. Instead, it outputs the list of instructions used to sort them, and the number of operations should be as small as possible.


# Instructions

## Compilation
### create executable
```
# create executable
 make

# re-create executable
 make re

# remove object files
 make clean

# remove object files and executable
 make fclean
```

## Execution
```
./push_swap "1 2 3"
```
### Error Handling
- program outputs `Error` in the following cases:
```
# empty argument
./push_swap
./push_swap ""

# non-integer values
./push_swap "1 2 3 h"

# integer overflow
./push_swap "1 2 3 -2147483649"

# duplicate values
./push_swap "1 2 3 2"
```

## Checker Usage
- Download the appropriate checker binary for your OS into the root directory.
- If permission is denied:
```
chmod 777 ./checker_<your OS>
```
- Example
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_<your OS> $ARG
```


# Algorithm Choices
Different strategies are applied depending on input size:

- 3 elements: hardcoded minimal combinations
- 2 elements: simple swap `sa`
- 4–5 elements: reduce to 3 elements, sort, then reinsert
- 6+ elements: radix sort (binary-based)

The radix sort operates on indexed values (after coordinate compression) and processes bits from least significant to most significant.


# Resources
## References
- [Stack and Queue concepts](https://qiita.com/drken/items/6a95b57d2e374a3d3292)
- [Radix sort explanation](https://tukumolog.com/radix-sort-introduction/)
- Linked list functions (libft bonus PDF)

## Use of AI
AI tools were used with the following objectives:

[understanding logic]
- clarifying parsing logic and sorting rules handling
- optimizing and validating sorting algorithm design
- visualizing sorting processes for deeper understanding

[error handling]
- verifying potential risks (e.g., memory leaks)
- identifying gaps between design assumptions and implementation results

[get any hint for code structuring]
- giving guidance on how to divide functions

[support language]
- assisting in README structuring
