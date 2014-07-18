# http://projecteuler.net/problem=48
# ans = 9110846700
# status = AC
import sys

def solve(N):

    i = 1
    s = 0
    
    while i <= N:
        s = s + i**i
        i = i + 1

    str_s = str(s)
    return str_s[-10:-1] + str_s[-1]

N = 1000
print solve(N)
