import sys

def solve(a,n,k):

    assert(len(a) >= 0)
    
    num_even = [0]*len(a)

    if a[0] % 2 == 0:
        num_even[0] = 1
    else:
        num_even[0] = 0

    i = 1

    while i < len(a):

        if a[i] % 2 == 0:
            num_even[i] = num_even[i - 1] + 1
        else:
            num_even[i] = num_even[i - 1]
        i = i + 1
   
    if k == 0:
        if num_even[-1] == len(a):
            return "NO"
        else:
            return "YES"

    if num_even[-1] >= k:
        return "YES"
    else:
        return "NO"

T = int(raw_input())

while T > 0:
    lnk = raw_input()
    lnk_ls = lnk.split()
    n = int(lnk_ls[0])
    k = int(lnk_ls[1])
    
    str_a = raw_input()
    str_als = str_a.split()

    a = []
    
    for c in str_als:
        a.append(int(c))

    print solve(a,n,k) 

    T = T - 1

