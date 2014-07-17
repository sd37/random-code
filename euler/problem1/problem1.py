#https://projecteuler.net/problem=1
#ans = 233168
#status = AC

import sys

def solve(N):
    
    i = 1
    
    s = 0

    while i < N:

        if(i % 3 == 0 or i % 5 == 0):
            s = s + i
        i = i + 1

    return s

print solve(1000)
