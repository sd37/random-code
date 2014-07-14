# https://oj.leetcode.com/problems/valid-palindrome/
# Status = AC

import sys
import re

class Solution(object):
    # @param s, a string
    # @return a boolean

    def isPalindrome(self,s):
        new_s = re.sub('[^a-zA-Z0-9]',"",s)
        new_s = new_s.lower()

        rev_new_s = new_s[::-1]

        return new_s == rev_new_s


soln = Solution()

s = "A man, a plan, a canal: Panama"

print soln.isPalindrome(s)
