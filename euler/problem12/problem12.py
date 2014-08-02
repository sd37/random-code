# https://projecteuler.net/problem=12
# status = AC
# ans = 76576500

import sys

def getTriangularNumber(i):

    return sum(range(1,i + 1))

def numOfFactors(N):

    factors = []
    
    i = 2

    while N > 1:
        while N % i == 0:
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

    ans = 1

    for p in primed:
        ans = ans * (primed[p] + 1)
        
    return ans

i = 1
DIV = 500
while True:
    t = getTriangularNumber(i)
    numfac = numOfFactors(t)
    if numfac >= DIV:
        print t
        break 
    i = i + 1
