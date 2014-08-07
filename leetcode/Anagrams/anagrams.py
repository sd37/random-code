# status = AC
import sys


class Solution:
    
    def alphasort(self,s):
        return ''.join(sorted(s))
    
    def anagrams(self, strs):
        
        anagrm = dict()

        for x in strs:

            if self.alphasort(x) not in anagrm:
                anagrm[self.alphasort(x)] = [x]
            else:
                anagrm[self.alphasort(x)].append(x)

        ans_l = []

        for k in anagrm:
            if len(anagrm[k]) > 1:

                for s in anagrm[k]:
                    ans_l.append(s)

        return ans_l

soln = Solution()

str_l = ["and","dan","spandan","naps"]

print soln.anagrams(str_l)
