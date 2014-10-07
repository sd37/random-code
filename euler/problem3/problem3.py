#https://projecteuler.net/problem=3
#ans = 6857 
#status = AC
import sys

def primeFactorization_On(N):
    
    i = 2
    factors = []

    while N > 1:
        
        while( N % i == 0) :
            factors.append(i)
            N = N / i
        
        i = i + 1
    
    print factors
    return factors


def primeFactorization_Osqrtn(N):
    
    i = 2
    factors = []

    while N > 1:
        
        while( N % i == 0) :
            factors.append(i)
            N = N / i

        i = i + 1
       
        if(i*i > N):
            if(N > 1):
                factors.append(N)
            break
    
    print factors
    return factors

def solve(N):
    
    factors = primeFactorization_Osqrtn(N)

    if(len(factors)):
        return max(factors)
    return 0

N = 600851475143
print solve(N)
