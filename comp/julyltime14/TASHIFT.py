import sys

def common_prefix(a,b):
    i = 0
    
    while i < len(a):
        if(a[i] != b[i]):
            return i 
        i = i + 1

def rotate(s,n):
    return s[n:] + s[:n]

def solve(N,A,B):

    r = 0
    r_max = r
    B_org = B
    max_len = common_prefix(A,B)

    while True:
        B = rotate(B,1)
        r = r + 1
        if(B == B_org):
            break
        cmlen = common_prefix(A,B)
        if max_len < cmlen:
            max_len = cmlen
            r_max = r

    return r_max



N = int(raw_input())
A = raw_input()
B = raw_input()

print solve(N,A,B)
