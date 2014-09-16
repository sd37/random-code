# status = AC.
# ans = 4075.

import sys
import math

def compute_nCr(n,r):
    ans = math.factorial(n) / (math.factorial(r) * math.factorial(n-r))
    return ans

def solve():
    n = 1
    c = 0;
    while(n <= 100):
        r = 0
        while r <= n:
            if compute_nCr(n,r) > 1000000:
                c = c + 1
            r = r + 1
        n = n + 1

    print c

solve()
