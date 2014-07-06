import sys

def solve(_s,_sz):

    _c = 0
    _ic = 0

    for ch in _s:
        
        if (ch == '1'):
            _ic = _ic + 1
        
        if (ch == '1'):
            _c = _c + _ic

    return _c

T = int(raw_input())

while T > 0:
    _sz = int(raw_input())
    _s = raw_input()
    ans = solve(_s,_sz)
    print ans
    T = T - 1
