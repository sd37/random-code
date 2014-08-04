# https://projecteuler.net/problem=13
# ans = 5537376230
# status = AC

import sys

s = 0

for l in sys.stdin:
    s = s + int(l)

print str(s)[0:10]

