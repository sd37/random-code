import sys

# d stands for dish
# di stands for the ith dish
# P represent the owner of a particular dish

def find(P,d):

    if P[d] == d:
        return d
    else:
        P[d] = find(P,P[d])
    
    return P[d]

def union(P,S,dx,dy):

    cx = find(P,dx)
    cy = find(P,dy)
    
    if(cx == cy):
        print "Invalid query!"
        return

    if( S[cx] < S[cy] ):
        P[cx] = cy
    elif(S[cx] > S[cy] ):
        P[cy] = cx
    else:
        pass

# read the inputs

T = int(raw_input())

while T > 0:
    N = int(raw_input())
    l = raw_input()
    ls = l.split()
    S = []
    
    for c in ls:
        S.append(int(c))
    
    assert len(S) == N

    P = range(N)
    
    numQ = int(raw_input())

    while numQ > 0:
        ql = raw_input()
        qls  = ql.split()

        if qls[0] == "0":
            dx = int(qls[1])
            dy = int(qls[2])
            union(P,S,dx - 1,dy - 1)
        
        else:
            assert qls[0] == "1"
            dx = int(qls[1])
            print find(P,dx - 1) + 1 

        numQ = numQ - 1
    
    T = T -1
