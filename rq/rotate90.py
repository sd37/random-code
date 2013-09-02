#http://www.talentbuddy.co/challenge/521574d14af0110af382acc9
#rotate matrix by 90
import re
def print_l(r):
    s = str(r)
    s = re.sub(","," ",s)
    s = s[1:len(s) - 1]
    print s
def display(arr):
    for r in arr:
	print_l(r)
    
def create_2darray(lines):
    dim = len(lines)
    Matrix = [[0  for x in xrange(dim)] for x in xrange(dim)]
    for i in range(dim):
	tkns = lines[i].split(",")
	for j in range(dim):
	    Matrix[i][j] = int(tkns[j])
    return Matrix	    	
	
def trp(arr):
    dim = len(arr[0])
    for i in range(dim-1):
	for j in range(i + 1,dim):
	    temp = arr[i][j]
	    arr[i][j] = arr[j][i]
	    arr[j][i] = temp
    return arr
def rev_col(arr):
    i = 0
    while i < len(arr[0]):
	arr[i].reverse()
	i = i + 1
    return arr

def rotate_matrix(lines):
    arr2d = create_2darray(lines)
    arr2d  = trp(arr2d) 	
    arr2d = rev_col(arr2d)
    display(arr2d)

lines = ["1,2,3","4,5,6","7,8,9"]
rotate_matrix(lines)


