import sys


def solve(l):
    i = 0
    maxand = -1

    while i < len(l):
        
        j = i + 1
        
        while j < len(l):
            
            if (maxand < (l[i] & l[j]) ):
                maxand = l[i] & l[j]
            
            j = j + 1
        
        i = i + 1

    return maxand

N = int(raw_input())
l = []
while N > 0:
    x = int(raw_input())
    l.append(x) 
    N = N - 1

print solve(l)
