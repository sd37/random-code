#https://projecteuler.net/problem=2
# ans = 4613732
# status = AC 

N = 4000000

import sys

def genFib(N):
    
    fib_l = [1,2]

    while True:

        nextfib = fib_l[-1] + fib_l[-2]

        if(nextfib >= N):
            break

        fib_l.append(nextfib)
    
    return fib_l

def solve(N):

    fib_l = genFib(N)

    s = 0

    for x in fib_l:
        if( x % 2 == 0): 
            s = s + x

    return s

print solve(N)
