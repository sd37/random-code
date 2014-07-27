# https://projecteuler.net/problem=5
# status = AC
# ans = 232792560
import sys

def primeFactors(N):

    i = 2
    factors = []

    while N > 1:
        
        while (N % i == 0):
            factors.append(i)        
            N = N / i
        
        i = i + 1

        if i*i > N:
            if N > 1:
                factors.append(N)
            break

    primed = dict()

    for p in factors:
        
        if p not in primed:
            primed[p] = 1
        else:
            primed[p] = primed[p] + 1

    return primed

def lcm(ln):
    
    assert(len(ln) >= 2)
    
    lcm_prime = dict()

    for x in ln:
        primed = primeFactors(x)
        
        for p in primed:

            if p not in lcm_prime:
                lcm_prime[p] = primed[p]
            else:
                if lcm_prime[p] < primed[p]:
                    lcm_prime[p] = primed[p]

    ans = 1

    for p in lcm_prime:
        ans = ans * (p ** lcm_prime[p])

    return ans

ln = range(1,20 + 1)
print lcm(ln)
