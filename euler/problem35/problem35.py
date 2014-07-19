# http://projecteuler.net/problem=35
# ans = 55
# status = AC

import sys
import math
from collections import deque

def genPrimes(N):

    isprime = [1]*N

    isprime[0] = 0
    isprime[1] = 0

    i = 2

    while i < math.sqrt(N):

        j = i * i

        while j < N:
            isprime[j] = 0
            j = j + i

        i = i + 1

    # extract the primes in a list

    i = 2
    primes = []

    while( i < len(isprime) ):
        if(isprime[i]):
            primes.append(i)
        i = i + 1

    return primes, isprime

def isCircular(x,isprime):
    
    str_x = str(x)

    g = deque(str_x)

    for i in range(len(g)):
        g.rotate(1)
        st = ""

        for c in g:
            st = st + str(c)

        tmp_i = int(str(st))
        
        if(not isprime[tmp_i]):
            return False

    #print x
    return True

def solve(N):

    [pr,isprime] = genPrimes(N)

    c = 0

    for x in pr:

        if(isCircular(x,isprime)):
            c = c + 1

    return c

print "total = " + str(solve(1000000))
