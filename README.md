# push_swap

push_swap is a small command-line program, written in C, that computes a sequence of stack operations to sort a list of distinct integers. The goal is to sort the input using a limited set of operations while keeping the number of moves as small as possible.

## What it does

Given a list of integers as command-line arguments, `push_swap` prints to standard output a sequence of operations (one per line) that will sort the numbers in ascending order when applied to two stacks (commonly called stack A and stack B). The program itself does not execute the operations — it only outputs the operations required.

## Supported operations

The operations printed by `push_swap` follow the usual push_swap instruction set:

- sa: swap the first two elements of stack A
- sb: swap the first two elements of stack B
- ss: sa and sb at the same time
- pa: push the top element from stack B to stack A
- pb: push the top element from stack A to stack B
- ra: rotate stack A (first element becomes last)
- rb: rotate stack B (first element becomes last)
- rr: ra and rb at the same time
- rra: reverse rotate stack A (last element becomes first)
- rrb: reverse rotate stack B (last element becomes first)
- rrr: rra and rrb at the same time

## Technical details

- Language: C
- Build system: Makefile
- Data structure: stacks implemented with linked lists (or simple node-based stacks)
- Input: command-line arguments, each an integer
- Output: list of operations (one per line) printed to stdout
- Error handling: invalid input (non-integer, duplicates, overflow) should be reported and the program exits with a non-zero status.

## Files in this directory

- `main.c` — program entry point; parses input and launches the algorithm
- `push_swap_init.c` — stack initialization and input parsing
- `stack_init.c` — helpers to create and manage stacks
- `stack_utils.c` — utility helpers for stack operations and validation
- `push_command.c` — implementation of push commands (`pa`, `pb`)
- `swap_command.c` — implementation of swap commands (`sa`, `sb`, `ss`)
- `rotate_command.c` — implementation of rotate commands (`ra`, `rb`, `rr`)
- `reverse_rotate_command.c` — implementation of reverse rotate commands (`rra`, `rrb`, `rrr`)
- `push_swap_command.c` — high-level command orchestration used by the algorithm
- `split.c` — helpers for argument splitting if arguments are given as a single string
- `tiny_sort.c` — optimized routines for sorting very small stacks (2, 3, 5 elements)
- `error_free.c` — error handling and memory cleanup
- `Makefile` — build rules
- `push_swap.h` — project headers and shared types

(Exact filenames reflect the repository contents.)

## Build

To compile the program, run the `make` rule in the `push_swap` directory. This will produce the `push_swap` binary.

```bash
make
# or, to force rebuild
make re
```

## Usage

Basic usage expects each integer as a separate argument:

```bash
./push_swap 3 2 1 6 5
```

You can also pass the numbers as a single quoted string (the project includes `split.c` to handle that case):

```bash
./push_swap "3 2 1 6 5"
```

The program prints a sequence of operations to stdout. To verify the operations, you can use a checker program (not included here) or implement a small tester that applies these operations to the input stacks.

## Examples

1) Already-sorted input produces no moves:

```bash
./push_swap 1 2 3 4 5
# (no output)
```

2) Small unsorted input:

```bash
./push_swap 2 1 3
# sample output:
# sa
```

3) Typical invocation where you want to see the moves applied (with a separate checker):

```bash
./push_swap 5 4 3 2 1 > moves.txt
# then feed moves.txt and the initial numbers to a checker program
```

## Algorithmic approach

This repository contains helpers for specialized small-input sorts (`tiny_sort.c`) and an algorithm that uses push/rotate operations to move values between the two stacks to build a sorted sequence. Common strategies used in push_swap implementations include:

- Special-case handlers for small N (2, 3, 5) to produce minimal moves.
- Partitioning or chunking the list and pushing chunks to stack B, then reinserting in order.
- Bitwise/radix style approaches for larger N.

The code arranges operations in modular command functions so different strategies can orchestrate those primitives.

## Error handling

- On invalid input (non-integer tokens, duplicates, integer overflow), the program should print an error message to stderr and exit with a non-zero status.
- Memory allocated should be freed on error paths; see `error_free.c` for related helpers.

## Testing

- Manual testing: run `./push_swap` with sample inputs and inspect the operation sequence.
- Automated testing: create a small script that applies the operations to the input and checks that the final stack is sorted.
