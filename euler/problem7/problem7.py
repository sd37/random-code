# https://projecteuler.net/problem=7
# ans = 104743
# status = AC

import sys
import math

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

    # extract the primes into a list

    primes = []

    i = 2

    while(i < len(isprime)):
        if(isprime[i]):
            primes.append(i)    
        i = i + 1

    return primes


pr = genPrimes(1000000)
print pr[10001 - 1]


