# push_swap

`push_swap` is a 42 School project focused on algorithmic optimization and data structure manipulation. The goal is to sort a stack of integers with the minimum number of instructions using only two stacks and a limited set of operations.

This version of `push_swap` uses a **cost-based sorting algorithm** ("Turkish method"), where each move is **evaluated before execution** to ensure the most optimal choice at every step.

---

## Project Goal

- Implement an efficient sorting algorithm using **only push_swap allowed instructions**
- Optimize for the **lowest possible number of operations**
- Handle a wide range of inputs (3 to 500 numbers) efficiently
- Practice algorithm design, edge case handling, and performance tuning

---

## Allowed Instructions

- `sa`, `sb`, `ss` — swap the top elements
- `pa`, `pb` — push to stack A or B
- `ra`, `rb`, `rr` — rotate (first element becomes last)
- `rra`, `rrb`, `rrr` — reverse rotate (last becomes first)

---

## Algorithm Used (Turkish Cost-Based Method)

This implementation uses a **cost evaluation approach**, where before moving any number from stack B to A:

1. All possible rotations are calculated (A & B).
2. The **total cost** for each number to be placed in its correct position is computed.
3. The **cheapest move** is selected and executed.
4. This process repeats until stack B is empty and stack A is fully sorted.

### Pros:
- Predictable and deterministic
- Good performance on mid to large inputs
- Easy to debug and analyze

### Cons:
- Can be brute-force-heavy for some inputs
- Less optimal than hard-coded patterns for very small input sizes
