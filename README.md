*This project has been created as part of the 42 curriculum by csilva-s*

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program uses two stacks (stack A and stack B) and a specific set of instructions to manipulate them.

The goal is to sort stack A in ascending order with the least amount of operations. Stack A starts with a random collection of integers, while stack B begins empty. The algorithm must be efficient, as the number of operations is evaluated and graded based on complexity.

This project develops skills in algorithm optimization, data structure manipulation, and computational complexity analysis.

## Instructions

### Compilation

To compile the project, run:
```bash
make
```

This will generate the `push_swap` executable.

Additional make rules:
- `make clean` - removes object files
- `make fclean` - removes object files and executables
- `make re` - recompiles the entire project

### Usage

Run the program with a list of integers as arguments:
```bash
./push_swap 3 2 5 1 4
```

The program will output the series of operations needed to sort the stack.

### Valid Input

- Only integers
- No duplicates
- Numbers must be within integer range

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Move the first element of B to the top of A |
| `pb` | Move the first element of A to the top of B |
| `ra` | Rotate all elements of A up by one position |
| `rb` | Rotate all elements of B up by one position |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Rotate all elements of A down by one position |
| `rrb` | Rotate all elements of B down by one position |
| `rrr` | Execute `rra` and `rrb` simultaneously |

### Example
```bash
./push_swap 2 1 3
```
Output:
```
sa
```

### Checker (Optional)

If you have a checker program, you can verify the sorting:
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

## Resources

### Documentation and Tutorials

- [Push Swap - Medium Article by Ayogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Comprehensive guide explaining the push_swap algorithm and implementation strategies
- [My Journey to Find a Good Sorting Algorithm for Push Swap](https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474) - Detailed exploration of different sorting approaches and algorithm optimization
- [Push Swap Visualization - YouTube](https://www.youtube.com/watch?v=GMV7ycKZ-mM) - Visual explanation of how the push_swap algorithm works

### AI Usage

AI (Claude by Anthropic) was used to assist with the following aspects of this project:

- **README Documentation**: Structuring and formatting the README file, including writing clear descriptions and organizing sections
- **Algorithm Understanding**: Clarifying concepts related to sorting algorithms and stack operations
- **Code Review**: Discussing implementation approaches and potential optimizations
- **Debugging Support**: Troubleshooting compilation issues and logical errors

All core algorithm logic and implementation were developed independently, with AI serving as a learning and documentation tool.
