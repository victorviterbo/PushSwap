# PushSwap

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
- **Reverse Rotate**: `rra`, `rrb`, `rrr` - shift all elements down (rrr = rra + rrb)

## 🚀 Usage
./push_swap 4 67 3 87 10
# With the Checker program
ARG="4 67 3 87 10"; ./push_swap_\<os\> $ARG | ./checker_\<os\> $ARG
