import sys


def solve(S, L, P):
    
    i = 0
    c = 0
    
    sz = len(S)

    seen = set()

    while True:
        substr = S[i:i + L]

        if(len(substr) != L):
            break

        if( (substr not in seen) and (S.count(substr) == P)):
            c = c + 1
            seen.add(substr)
        i = i + 1

    return c

S = raw_input()

N = int(raw_input())

while N > 0 :
    
    line = raw_input()

    q = line.split()

    q = [int(x) for x in q]

    L = q[0]

    P = q[1]

    ans = solve(S, L, P)

    print ans

    N = N - 1
