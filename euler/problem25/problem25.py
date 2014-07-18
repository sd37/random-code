# https://projecteuler.net/problem=25
# ans = 4782
# status = AC

import sys

def solve():
    
    last2 = 1
    last1 = 1
    nterm = 2
    while True :

        nextfib = last1 + last2
        nterm = nterm + 1
        last2 = last1
        last1 = nextfib
        
        if(len(str(nextfib)) == 1000):
            print nterm
            break
        
solve()
