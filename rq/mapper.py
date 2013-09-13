import re

class redict(dict):
    def __init__(self,d):
        dict.__init__(self,d)

    def __getitem__(self, regex):
        r = re.compile(regex)
        mkeys = filter(r.match, self.keys())
        
        for i in mkeys:
            yield dict.__getitem__(self,i)
            
def print_l(l):
    s = ""
    for x in l:
        s = s + str(x) + " "
    return s

def inv_index(docs):
    inv_ind = dict()
    doc_id = 0
    for d in docs:
        new_d = re.sub(r'[?!,]'," ",d) 
        ld = new_d.split()
        for x in ld:
            if x not in inv_ind:
                inv_ind[x] = [doc_id]
            else:
                inv_ind[x].append(doc_id)

        doc_id = doc_id + 1    
    return inv_ind


def mr_map(search_strings,docs):
    inv_ind = inv_index(docs)
    inv_ind = redict(inv_ind)

    for x in search_strings:
        ans = []
        regexp = ".*" + x +".*"
        for i in inv_ind[regexp]:
            ans = ans + i
        
        if ans == []:
            print "-1"
        else:
            print print_l(sorted(ans))


mr_map(["buddy","code","talent"],["Hello, buddy!","Got talent? Who's your buddy?"])
