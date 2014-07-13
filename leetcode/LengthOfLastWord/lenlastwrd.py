import sys

class Solution(object):
    
    # @param s, a string
    # @return an integer

    def lengthOfLastWord(self,s):
        
        parts = s.split()
        
        if(len(parts)):
            return len(parts[-1])
        else:
            return 0


s = "this is the shit"

soln = Solution()
print soln.lengthOfLastWord(s)
