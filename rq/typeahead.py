#http://www.talentbuddy.co/challenge/5233cc274af0110af382f4105233cc274af0110af382f40e

import re
def print_l(ans):
    s = ""
    for x in ans:
        s = s + x + " "
    print s

def typeahead(usernames, queries):
    for q in queries:
        pattern = q + ".*"
        regex = re.compile(pattern,re.IGNORECASE)
        ans_l = filter(regex.match,usernames)
        ans_l = sorted(ans_l,key=str.lower)
        if ans_l:
            print ans_l[0]
        else:
            print "-1"

usernames = ["ArmindaJoanna","CreolaOnie","JeanineCarol","Luther","AnnelleLouvenia","LuigiTrista"]
queries   = ["ANNe","L","CR","AnNeLl"]
typeahead(usernames, queries)
