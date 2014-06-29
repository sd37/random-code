#http://discuss.codechef.com/questions/46072/smpair-editorial
import sys

def solve(a, sz):
    a.sort()

    return a[0] + a[1]

_num_test = int(raw_input());

while _num_test > 0:

    _sz = int(raw_input());
    elm = raw_input();
    array = elm.split();
    array = [int(x) for x in array];
    
    ans = solve(array,_sz)
    print ans

    _num_test = _num_test - 1;
