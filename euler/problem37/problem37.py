# https://projecteuler.net/problem=37
# ans = 748317
# status = AC

import sys

def isPrime(N):
    
    N = abs(N)
    if N <= 1:
        return False

    i = 2

    while i*i <= N:
        if N % i == 0:
            return False
        i = i + 1

    return True

def isTrunc(N):

    str_N = str(N)

    # left to right
    
    i = 0
    lr = True

    while i < len(str_N):

        temp = int(str_N[i:])

        if(not isPrime(temp)):
            lr = False
            break

        i = i + 1 

    # right to left

    i = 0

    rl = True

    while i < len(str_N):

        temp = int(str_N[0:len(str_N) - i])
        
        if(not isPrime(temp)):
            rl = False
            break

        i = i + 1

    return (lr and rl) 

def solve():

    l = []
    
    i = 11

    while True:

        if len(l) == 11:
            return l
        
        if(isTrunc(i)):
            l.append(i)

        i = i + 1


l = solve()
print l
print sum(l)
