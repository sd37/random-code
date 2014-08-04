# https://projecteulet.net/problem=9
# ans = 31875000
# status = AC

import sys

P = 1000

def solve():

    a = 1
    while a < P:
        b = 1
        while b < P - a:
            
            c = P - (a + b)

            if(a**2 + b**2 == c ** 2):
                print [a,b,c]
                return a*b*c
    
            b = b + 1

        a = a + 1

print solve()
