#https://projecteuler.net/problem=47
#ans = 134043
#status = AC

import sys

primes = 4
LIM = 1000000


def find_consec(N,l):

    i = 0

    while i < (len(l) - N):
        
        if(l[i] + 1 == l[i + 1] and l[i] + 2 == l[i+2]
                and l[i] + 3 == l[i + 3]):
            return l[i]

        i = i + 1

def numOfDistinctPrimeFactors(N):
    
    i = 2
    
    factors = []

    while N > 1:
        while N % i == 0:
            factors.append(i)
            N = N / i

        if i * i > N :
            if N > 1:
                factors.append(N)
            break
        i = i + 1

    return len(set(factors))

def solve():
    
    s = []

    i = 2

    while i < LIM:
        if(numOfDistinctPrimeFactors(i) == primes):
            s.append(i)
        i = i + 1
    #print s 
    print find_consec(primes,s)
solve()
