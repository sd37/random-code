# https://projecteuler.net/problem=6
# status = AC
# ans = 25164150

import sys

def sumOfSquares(N):

    s = 0

    for i in xrange(1,N + 1):
        s = s + i ** 2

    return s

def squareOfSum(N):

    s = 0

    for i in xrange(1, N + 1):
        s = s + i

    return s ** 2

def solve(N):

    return (squareOfSum(N) - sumOfSquares(N))

print solve(100)
