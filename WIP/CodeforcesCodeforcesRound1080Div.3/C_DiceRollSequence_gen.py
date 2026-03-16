#!/usr/bin/env python3
"""
Test case generator for Dice Roll Sequence (CF 2195 C).
Output format: same as problem input (t, then for each test: n, then n integers in [1,6]).

Usage:
  python3 C_DiceRollSequence_gen.py [seed] [t] [n_min] [n_max]   # random
  python3 C_DiceRollSequence_gen.py 42 5 1 20                     # 5 tests, n in [1,20]

Then:
  python3 C_DiceRollSequence_gen.py 42 10 1 15 > C_DiceRollSequence.in1
  ./C_DiceRollSequence_brute < C_DiceRollSequence.in1 > C_DiceRollSequence.ans_brute
  ./C_DiceRollSequence < C_DiceRollSequence.in1 > C_DiceRollSequence.ans_main
  diff C_DiceRollSequence.ans_brute C_DiceRollSequence.ans_main
"""

import random
import sys

def main():
    seed = int(sys.argv[1]) if len(sys.argv) > 1 else None
    t = int(sys.argv[2]) if len(sys.argv) > 2 else 5
    n_min = int(sys.argv[3]) if len(sys.argv) > 3 else 1
    n_max = int(sys.argv[4]) if len(sys.argv) > 4 else 15

    if seed is not None:
        random.seed(seed)

    print(t)
    for _ in range(t):
        n = random.randint(n_min, n_max)
        a = [random.randint(1, 6) for _ in range(n)]
        print(n)
        print(" ".join(map(str, a)))

if __name__ == "__main__":
    main()
