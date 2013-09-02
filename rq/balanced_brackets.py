class Stack(object):
    def __init__(self):
	self.storage = []
    def __repr__(self):
	return str(self.storage)
    

    def push(self,e):
	self.storage.append(e)
    def pop(self):
	if self.isEmpty():
	    return 'Empty'
	return self.storage.pop()
    def isEmpty(self):
	return not bool(self.storage)

	

def balanced_brackets(s):
    stack = Stack() 
    str_l = len(s)
    flag = 0
    i = 0
    while i < str_l:
	if i == 0 and s[0] == ')':
	    break
	elif s[i] == '(':
	    stack.push(s[i])
	    i = i + 1
	elif s[i] == ')':
	    c = stack.pop()	
	    if c == '(':
		i = i + 1
		continue
	    elif c == "Empty":
		break
	    else:
		break
    if i == len(s) and stack.isEmpty():
	flag = 1
    else:
	flag = 0
    
    if flag:
	print "Balanced"
    else:
	print "Unbalanced"
		
	     
#s = "(())())"
s = "(()())"
balanced_brackets(s)
