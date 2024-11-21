'''
python3 main.py < input.txt
oj t -c "python3 ./main.py" -d ./tests/
N = int(input())
A = list(map(int, input().split()))
B = [] * N
sys.setrecursionlimit(1000000)
'''

import sys
import math
import heapq
import itertools
import numpy as np
from collections import deque
from functools import reduce
from string import ascii_lowercase

# main
def main():
    print(np.__version__)

# エントリポイント
if __name__ == '__main__':
    main()