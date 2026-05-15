# Push_swap - Advanced Algorithmic Sorting

## 📊 General Project Architecture

The `push_swap` project is an algorithmic challenge focused on data sorting. The goal is to sort a random list of integers using two stacks (`a` and `b`) and a highly restricted set of operations, aiming to generate the absolute minimum number of instructions.

Rather than just writing a single sorting function, this project implements a dynamic sorting engine that evaluates the "disorder" of the input and selects the most efficient algorithmic strategy on the fly.

### 🔹 Main Modules

- **Input Parser & Validator**
  - Reads integers from standard input.
  - Validates constraints (no duplicates, valid integer ranges, no strings).
  - Initializes Stack `a` and calculates the initial Disorder Index.

- **Sorting Engine (Core)**
  - Calculates the most optimal sorting strategy based on mathematical complexity constraints.
  - Generates the sequence of operations (pushes, swaps, and rotations) to sort the stack.

- **Bonus: The Checker**
  - A secondary program that reads the generated instructions via standard input and verifies if they correctly sort the initial stack.
---

## 👨‍💻 Algorithmic Strategies & Complexity

To handle different input sizes and states efficiently, the project implements four distinct sorting architectures.The complexity is measured strictly by the number of stack operations generated.

### 1. Simple Sort $O(n^2)$
- Baseline algorithm (e.g., Insertion or Selection sort adaptation)[cite: 184, 185, 186].
- **Advantages:** Easy to implement, zero overhead for extremely small sets.
- **Disadvantages:** Scales terribly. Unusable for large datasets.

### 2. Intermediate Sort $O(n\sqrt{n})$
- Block-based algorithm (e.g., Chunk sort or Bucket sort with $\sqrt{n}$ buckets).
- **Advantages:** Drastically reduces operations for medium-sized stacks compared to the simple approach.
- **Disadvantages:** Slower than complex algorithms for massive datasets.

### 3. Complex Sort $O(n \log n)$
- High-efficiency algorithm (e.g., Radix sort, Merge sort, or Quicksort).
- **Advantages:** Highly scalable, providing excellent performance for large, completely randomized stacks.
- **Disadvantages:** Can be overkill or inefficient for lists that are already partially sorted.

### 4. Custom Adaptive Sort
- A dynamic approach that pre-calculates a **Disorder Index** (from $0.0$ to $1.0$).
- It evaluates all pairs of numbers to detect sorting "mistakes" (larger numbers appearing before smaller ones).
- Dynamically routes execution:
  - **$< 0.2$ (Nearly sorted):** Routes to $O(n)$ optimizations.
  - **$0.2 - 0.5$ (Moderately mixed):** Routes to $O(n\sqrt{n})$ strategy.
  - **$\ge 0.5$ (Highly chaotic):** Routes to $O(n \log n)$ strategy.

---

## ⚙️ Usage & Execution

### Compilation

The project is equipped with a `Makefile`. To compile the main program:
```bash
make
```
## 📊 Visual Summary of Adaptive Execution

| Disorder Index | Data State | Selected Strategy | Expected Output |
|----------------|------------|-------------------|-----------------|
| `0.00 - 0.19` | Nearly Sorted | Linear O(n) | Minor local swaps |
| `0.20 - 0.49` | Medium Chaos | Chunks O(n√n) | Block groupings |
| `0.50 - 1.00` | Full Chaos | Radix/Merge O(n log n) | Heavy stack passing |


## 🖋️ Commit Conventions

During the development of this project, a standardized commit history was maintained to identify changes easily:

| Prefix       | Description                                              |
|--------------|----------------------------------------------------------|
| `[FEAT]`     | To add a new functionality                               |
| `[FIX]`      | To fix an error or bug                                   |
| `[REFACTOR]` | Internal improvements without changing functionality     |
| `[DOCS]`     | For documentation changes                                |
| `[TEST]`     | To add or modify tests                                   |
