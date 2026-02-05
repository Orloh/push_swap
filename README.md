*This project has been created as part of the 42 curriculum by orhernan.*

# Push_Swap

## Project Description
Push Swap is a sorting algorithm project developed as part of the 42 School Common Core curriculum. 
The goal is to sort a stack of integers using two stacks (A and B) and a limited set of operations, aiming to achieve the sorting with the minimal number of instructions possible.

The program takes a list of integers as input and outputs a sequence of operations to sort the stack in ascending order. It handles duplicates, invalid inputs, and edge cases gracefully.

**Key features:**
- Efficient parsing and validation of input arguments.
- Ranking system to handle any integer values by converting them to ranks (0 to n-1).
- Hybrid sorting approach:
- For small stacks (≤5 elements): Optimized insertion-like sort with hardcoded patterns for 3 elements.
- For larger stacks: Binary radix sort (LSD) with aggressive early-exit optimizations to minimize operations.

**Performance:** Achieves ~857 operations for 100 elements and ~5740 for 500 elements on average, meeting the project's benchmark requirements.

This project explores algorithm optimization, data structures (linked lists), and efficient manipulation under constraints.

## Instructions

### Requierments
- `make` is used to automate compilation of the source code
- `cc` the C compiler used to compile the source files
- `ar` the utility used to create static libraries
- `libft` custom C library with reimplemented standard functions
- `ft_printf` custom version of the `printf` function

### Compilation
To compile the program, navigate to the project root and run:

    make

This will generate the executable `push_swap`.

**Clean up:** use `make clean` to remove object files, `make fclean` to also remove the executable, or `make re` to recompile.

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87
```
- Single string input: `./push_swap "4 67 3 87 23"`
- Output: A sequence of operations
    pb
    ra
    sa

- If already sorted or invalid input: No output or `Error` on stderr.

To test with a checkker (bonus part, if implemented):

    ./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23a

Outputs `OK` if sorted correctly, `KO` otherwise.

For random testing:

    ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux

## Technical Choices

- **Data Structures:** Linked lists (`t_list` from libft) for stacks to allow efficient rotations and pushes.
- **Ranking:** Binary search for rank assignment to handle large/negative integers efficiently.
- **Optimizations:** Aggressive consecutive checks after each operation in radix passes to exit early, caching sizes to reduce traversals.
- **File Structure:** Modular with separate files for operations, parsing, small/big sorts, and utilities.

## Resources

### Documentation and Tutorials:
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort) -- Basis for big sorting
- [Oceano's Push_Swap](https://www.youtube.com/watch?v=OaG81sDEpVk&t=1135s) -- Helpful overview on how to solve the problem
- [Push swap online visualizer](https://www.youtube.com/watch?v=OaG81sDEpVk&t=1135s) -- Used to visualize the algo and detect optimizations.

### AI Usage:
AI (Grok and Gemini) was used to generate commmit messages, refactoring suggestions, documentation and drafting this README.md file, coode organization suggestions.

