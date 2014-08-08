import sys

class Solution:
    
    def transpose(self,m):
        r = len(m)
        c = len(m[0])

        tran_m = [ [0 for x in xrange(c)] for x in xrange(r) ]

        i = 0

        while i < r:
            j = 0
            while j < c:

                tran_m[i][j] = m[j][i]
                j = j + 1

            i = i + 1
        
        return tran_m
    
    def rotate(self,m):

        tran_m = self.transpose(m)

        for r in tran_m:
            r.reverse()

        return tran_m

soln = Solution()

a = [
     [1,2,3],
     [4,5,6],
     [7,8,9]
    ]

print soln.rotate(a)
