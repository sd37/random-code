#https://oj.leetcode.com/problems/reverse-words-in-a-string/
#status = AC
import sys

class Solution(object):
    # @param s, a string
    # @return a string

    def reverseWords(self,s):

        # reverse entire string

        s = s[::-1]

        ls = s.split()
        new_ls = []
        
        # reverse individual words

        for x in ls:
            new_ls.append(x[::-1])
        
        new_s = ""

        for x in new_ls:
            new_s = new_s + x + " "
    
        #delete last char as it is a space 

        return new_s[:-1]


soln = Solution()

s = "  the    sky   is   blue   "
print soln.reverseWords(s)

