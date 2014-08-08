# https://projecteuler.net/problem=16
# status = AC
# ans = 1366

import sys

def sum2(x,N):

    num_str = str(x ** N)

    s = 0

    for c in num_str:

        s = s + int(c)

    return s

print sum2(2,1000)

