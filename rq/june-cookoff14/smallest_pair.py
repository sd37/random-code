import sys

def solve(a, sz):
    
    i = 0;
    j = i + 1;
    curmin = a[i] + a[j];

    while i < sz - 1:
        j = i + 1;
        while j < sz:

            if(curmin > (a[i] + a[j])):
                curmin = a[i] + a[j];
            j = j + 1

        i = i + 1;
    
    return curmin


_num_test = int(raw_input());

while _num_test > 0:

    _sz = int(raw_input());
    elm = raw_input();
    array = elm.split();
    array = [int(x) for x in array];
    
    ans = solve(array,_sz)
    print ans

    _num_test = _num_test - 1;
