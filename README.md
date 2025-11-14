# 🫸 PushSwap 🔄

A highly efficient sorting algorithm project. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, with the fewest number of moves.

## 🎯 The Challenge
Sort a stack of integers using only:
- Two stacks: `a` (initial stack) and `b` (helper stack)
- Limited operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Minimize the number of operations

## 🔧 Available Operations
- **Swap**: `sa`, `sb`, `ss` - swap first two elements (`ss == sa + sb`)
- **Push**: `pa`, `pb` - push from one stack to another
- **Rotate**: `ra`, `rb`, `rr` - shift all elements up (`rr == ra + rb`)
- **Reverse Rotate**: `rra`, `rrb`, `rrr` - shift all elements down (`rrr = rra + rrb`)

## How it works
- step 0: All `N` passed numbers are on stack A
- step 1: We find the longest possible increasing sequence (LIS), keeping in mind that the possible operations turns the stack into a ring.
	- `O(1.5 N)`
- step 2: We push the elements of this sequence on the stack B. Lets say this sequence is of size l (necessarily `l >= 2`). 
	- `O(N)`
- step 3: Then for i ranging from 0 to N - l, we perform the following
	- For each element of the stack B, we compute the cost associated with it's insertion into A in it's correct place.
	- In the worst case senario, an insertion will need at most
        - `(N - l - i) / 2`  operations to bring that element to the top, leveraging the ring-like properties of the stack
        - `1` to push that element on A
        - `(l + i) / 2` operations to bring that element to any position in A
    - Which simplifies to `1 + N / 2`operations
    - We then proceed to insert the element of B with the lowest total associated cost
- step 4: All elements are in their correct place on the stack A. We simply have to rotate it until the smallest element is on top.

The worst case scenario for our algorithm is hence `O(n) = 1.5 N + N + (N - l) * (1 + N / 2)`. Since `l >= 2` we have `O(n) = 2.5 N + N ** 2 / 2`.
This may seem expenssive, but to average performance is much better, this comes from the fact that we perform always the cheapest move at each of the `N - l` iterations (step 3). If the cost associated with each insertion follows a uniform distribution, the lowest of `N - l - i` samples of this distribution should be quite low. This is especially true when i is low, so the opportunities for a "cheap" reinsertion are numerous.

## 🚀 Usage
`bash
ARG="4 67 3 87 10"; ./push_swap_<os> $ARG
`
# 🕵️ With the Checker program
`bash
ARG="4 67 3 87 10"; ./push_swap_<os> $ARG | ./checker_<os> $ARG
`
