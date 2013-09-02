#http://www.talentbuddy.co/challenge/51e486994af0110af3827b15
import collections
def display(dq):
    s = ""
    for e in dq:
	s = s + str(e) + " "
    print s
def nth_perm(v,n):
    dq = collections.deque(v)
    dq.rotate(n)
    display(dq)

nth_perm([7,1,2],4)
