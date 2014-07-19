# https://projecteuler.net/problem=30
# ans = 443839
# status = AC

import sys

def checkNthPower(x,N):

    str_x = str(x)
    
    power_sum = 0

    for c in str_x:
        power_sum = power_sum + (int(c)) ** N

    if power_sum == x:
        return True
    
    return False

def solve(N):

    l = []

    LIM = 1000000
    i = 2

    while i <= LIM:
        
        if(checkNthPower(i,N)):
            l.append(i)

        i = i + 1

    if (len(l)):
        return sum(l)
    else:
        return 0

print solve(5)

