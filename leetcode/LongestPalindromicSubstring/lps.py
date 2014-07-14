import sys
import re

class Solution(object):
    
    # @return a string

    def longestPalindrome(self,s):
        
        new_s = re.sub('[^a-zA-Z0-9]',"",s)
        new_s = new_s.lower()
        rev_s = s[::-1]

        i = 0
        
        max_len = -99 
        max_substr = ""

        while i < len(new_s):
            
            j = i + 1
            
            while j <= len(new_s):
                
                substr = new_s[i:j]    
                
                if(substr in rev_s and max_len < len(substr)):
                    max_len = len(substr)
                    max_substr = substr

                j = j + 1
            
            i = i + 1

        return max_substr

soln = Solution()
s = "abcdxyzyxabcdaaa"
print soln.longestPalindrome(s)
