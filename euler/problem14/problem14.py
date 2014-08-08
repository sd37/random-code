# https://projecteuler.net/problem=14
# status = AC
# ans = 837799

import sys

N = 1000000
def seqGen(x):

    c = 1

    while x != 1:
        
        if x % 2 == 0:
            x = x / 2
        else:
            x = 3*x + 1

        c = c + 1

    return c

def solve():

    i = 1
    
    ans = 0
    ans_l = -1

    while i < N:
        
        seq_l = seqGen(i)
        if(ans_l < seq_l):
            ans = i
            ans_l = seq_l

        i = i + 1

    return ans


print solve()
