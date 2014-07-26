# FROGV
# status = AC
# concept = Union Find [no optimization required]

import sys

def union(subsets, x, y):

    px = find(subsets,x)
    py = find(subsets,y)

    subsets[px] = py

def find(subsets,i):

    if i == subsets[i]:
        return i

    return find(subsets, subsets[i])

def unionFind(K, pos):
    subsets = [0]*len(pos)

    for i in range(len(pos)):
        subsets[i] = i
    
    
    pos_sort_l = sorted(enumerate(pos), key=lambda x: x[1])

    i = 0

    while i < len(pos) - 1:

        if( (pos_sort_l[i + 1][1] - pos_sort_l[i][1]) <= K ):
            union(subsets, pos_sort_l[i + 1][0], pos_sort_l[i][0])

        i = i + 1

    return subsets
    
def ans_query(subsets, x1, x2):

    px1 = find(subsets, x1)
    px2 = find(subsets, x2)

    if(px1 == px2):
        return "Yes"
    else:
        return "No"
        

l1 = raw_input()

ls1 = l1.split()

N = int(ls1[0])
K = int(ls1[1])
P = int(ls1[2])

l2 = raw_input()

ls2 = l2.split()

pos = []

for x in ls2:
    pos.append(int(x))

# ans P queries
subsets = unionFind(K,pos)

while P > 0:
    ll = raw_input()
    lls = ll.split()
    x1 = int(lls[0])
    x2 = int(lls[1])
    print ans_query(subsets, x1 - 1, x2 - 1)
    P = P - 1
