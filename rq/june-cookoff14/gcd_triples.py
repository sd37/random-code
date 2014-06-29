import sys
from fractions import gcd

def solve(a, N):
    
    if N < 3:
        return 0

    i = 0;
    c = 0

    while i <= N - 3:
        j = i + 1
        while j <= N - 2:
            k = j + 1
            while k <= N - 1:
                
                if( gcd(a[i], gcd(a[j],a[k]) ) == 1 ):
                    c = c + 1
                k = k + 1
            
            j = j + 1
        
        i = i + 1
    
    return c

N = int(raw_input())

elm = raw_input()
array = elm.split()
array = [int(x) for x in array]

ans = solve(array, N)

print ans
