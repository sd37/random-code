# https://projecteuler.net/problem=10
# ans = 142913828922
# status = AC

import sys
import math

def genPrimes(N):
    # generates all primes less than N
    
    isprime = [1] * N

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

    while(i < len(isprime)):
        
        if(isprime[i]):
            primes.append(i)

        i = i + 1

    return primes

pr = genPrimes(2000000)
#print pr
print sum(pr)
