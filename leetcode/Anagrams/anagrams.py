# status = AC
import sys

def alphasort(s):
    return ''.join(sorted(s))

class Solution:
    
    def anagrams(self, strs):
        
        anagrm = dict()

        for x in strs:

            if alphasort(x) not in anagrm:
                anagrm[alphasort(x)] = [x]
            else:
                anagrm[alphasort(x)].append(x)

        ans_l = []

        for k in anagrm:
            if len(anagrm[k]) > 1:

                for s in anagrm[k]:
                    ans_l.append(s)

        return ans_l

soln = Solution()

str_l = ["and","dan","spandan","naps"]

print soln.anagrams(str_l)
