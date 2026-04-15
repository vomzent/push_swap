*This project has been created as part of the 42 curriculum by odschreu, vcoevert.*

# push_swap

## Description

`push_swap` sorts a stack of integers using a limited set of operations across two stacks (`a` and `b`). The goal is to produce the shortest possible sequence of operations that leaves stack `a` sorted in ascending order (smallest at top).

The program implements four distinct sorting strategies selected either via a command-line flag or automatically by an adaptive algorithm that measures the disorder of the input.

## Instructions
 
**Compile:**
```bash
make
```
 
**Run:**
```bash
./push_swap [--simple | --medium | --complex | --adaptive] <integers...>
```
 
**Strategy flags:**
| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Disorder-based selection | varies |
 
If no flag is given, `--adaptive` is used by default.
 
**Benchmark mode** (outputs metrics to stderr):
```bash
./push_swap --bench --adaptive 4 67 3 87 23
```
 
Count operations (requires `shuf`, available on linux):
```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

> remove wc -l to see the operations
 
Verify correctness and view benchmark metrics:
```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2> bench.txt
cat bench.txt
```

**Error handling:**
```bash
./push_swap 1 two 3       # Error
./push_swap 1 1 2         # Error (duplicate)
./push_swap               # (no output)
./push_swap --hello		  # Error (invalid flag)
./push_swap --simple --medium  # Error (two strategies defined)
./push_swap --bench --simple --complex # Error (three flags, double definiton of strategy)
```

## Algorithms

### Disorder metric

Before selecting a strategy, the program computes a disorder value between 0 and 1. Disorder counts all pairs (i, j) where i < j but `a[i] > a[j]` (inversions / 'mistakes'), divided by total pairs. A perfectly sorted stack has disorder 0; a fully reversed stack has disorder 1. 

```
disorder = inversion_count / (n * (n-1) / 2)
```

This is computed before any moves are made.

---

### Simple — Selection sort O(n²)

Finds the minimum of stack `a`, rotates it to the top, pushes it to `b`, repeats. Once all elements are in `b` in descending order, pushes everything back to `a`.

Each pass requires up to O(n) rotations to find and retrieve the minimum, repeated n times → **O(n²) operations**.

Space: O(1) auxiliary (no extra data structures beyond the two stacks).

---

### Medium — Chunk sort O(n√n)

1. **Normalize:** assign each element a rank from 0 to n−1, converting arbitrary integers to a contiguous range. This ensures even chunk distribution.
2. **Partition into √n chunks** of size √n each, defined by rank ranges [0, √n−1], [√n, 2√n−1], etc.
3. **Push phase:** for each chunk (lowest ranks first), scan stack `a` to find the **cheapest element** in that chunk — the one reachable with the fewest rotations, considering both forward (`ra`) and reverse (`rra`) rotation. That element is rotated to the top and pushed to `b`. This greedy cheapest-first selection avoids always rotating to position 0 and instead picks whichever in-range element costs the least to reach. Each chunk pass costs O(n) rotations × √n chunks = **O(n√n) push operations**.
4. **Retrieve phase:** pull elements back from `b` to `a` in descending rank order, chunk by chunk (highest chunk first). For each element, scan `b` to find its position, rotate it to the top, then `pa`. This phase is O(n) elements × O(n) rotations worst-case = **O(n²) retrieval**, but with a much smaller constant than the naive O(n²) sort.

Overall: O(n√n), dominated by the push phase.

---

### Complex — Radix sort LSD O(n log n)

Radix sort works by sorting elements one bit at a time, from the least significant bit (LSB) to the most significant bit (MSB). Because ranks are assigned in the range [0, n−1], only ⌈log₂n⌉ bits are ever needed — so for 500 elements, that's just 9 passes.

Each pass partitions the stack into two groups based on the current bit:
- Elements with a **0** bit at position `k` are pushed to `b`.
- Elements with a **1** bit at position `k` stay in `a` (rotated to the bottom via `ra`).
- Once all elements have been examined, everything in `b` is pushed back to `a`.

After this, the stack is ordered such that all 0-bit elements (for that bit position) come before all 1-bit elements — exactly like a stable partition. Repeating this for every bit position from LSB to MSB produces a fully sorted stack, because binary numbers sorted digit-by-digit from least to most significant end up in correct order.

Concretely for each pass:
1. Iterate through all n elements of `a`.
2. If the current element's rank has a 0 at bit `k` → `pb`.
3. If it has a 1 → `ra`.
4. After the full pass, `pa` everything from `b` back to `a`.

Each pass uses exactly n `pb`/`ra` operations plus up to n `pa` operations = O(n) per pass. With ⌈log₂n⌉ passes total → **O(n log n) operations**.

Space: O(1) auxiliary (no arrays, no recursion — just the two stacks).

---

### Adaptive algorithm

Measures disorder before sorting and selects the appropriate strategy:

| Disorder range | Strategy selected | Target complexity |
|---------------|-------------------|-------------------|
| < 0.2 | Insertion-based (in-place rotations) | O(n) |
| 0.2 – 0.5 | Chunk sort | O(n√n) |
| ≥ 0.5 | Radix sort LSD | O(n log n) |

**Rationale for thresholds:**

- **< 0.2 (low disorder):** The stack has very few inversions. A targeted rotation strategy can fix each out-of-place element with a constant number of moves, yielding O(n) total operations. Chunk sort would overkill a nearly-sorted sequence.
- **0.2–0.5 (medium disorder):** Enough disorder that O(n) approaches break down, but not so chaotic that full bit-level sorting is necessary. Chunk sort handles this range efficiently and has a smaller constant than radix for mid-range inputs.
- **≥ 0.5 (high disorder):** The stack is largely scrambled. Radix sort's O(n log n) guarantee with low constants makes it the best choice here.

**Space complexity (all strategies):** O(n) total stack space (unavoidable given the problem model). No additional heap allocations beyond the linked list nodes themselves and the dynamic memory allocated for the amount of arguments (both in parsing and creating an int array of elements that need to be pushed on Stack A for initialization for the sorting).

---

## Performance targets

| Input size | Pass | Good | Excellent |
|-----------|------|------|-----------|
| 100 elements | < 2000 ops | < 1500 ops | < 700 ops |
| 500 elements | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Resources
A big shoutout to fellow codam students, namely lblonk for guidance with radix sort. Medium articles about the push swap project from other 42 students have also been very helpful to orientate the possible ways to Rome (getting an adequately efficient algorithm). 

As a team, we have also had a lot of support and guidance from each other (discussions about possible implementations, debugging together, asking each other questions). 

Some of the medium articles that have been of great help with understanding how to attack this project / get a feeling for push_swap:
- [Radix sort for push_swap — Leo Fu (Medium)](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Turk algorithm — A. Yigit Ogun (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Sort with two stacks — LeetCode wiki](https://leetcode.fandom.com/wiki/Sort_with_two_stacks)
- [Push_swap in less than 4200 operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)
- Bitwise operators — C reference / man pages
- YouTube tutorials on stack data structures
- Wikipedia pages on sorting algorithms (even array implementations, just to understand the sorting algorithm's approach)

**AI usage:** Claude (Anthropic) was used to understand theory, reasoning through complexity trade-offs between different sorting, and help drafting this README. All decisions and code were written, reviewed, understood, and implemented by both team members.