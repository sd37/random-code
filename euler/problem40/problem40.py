# https://projecteuler.net/problem=40
# ans = 210
# status = AC

import sys

def formNumber():

    i = 1
    
    num = ""

    while True:

        if(len(num) >= 1000000):
            break
        num = num + str(i)
        i = i + 1
    
    return num

def solve():
    
    num = formNumber()

    return (int(num[1 - 1]))* (int(num[10 - 1])) * (int(num[100 -1])) * (int(num[1000 - 1])) * (int(num[10000 - 1])) * (int(num[100000 - 1])) * (int(num[1000000 - 1]))


print solve()
