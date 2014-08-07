# status = AC
import sys

class Solution:

    def isNumber(self,s):
        
        try:

            x = float(s)

        except ValueError:
            return False

        return True


soln = Solution()

print soln.isNumber("+123")
