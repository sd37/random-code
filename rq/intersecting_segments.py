'''
def tuple_to_str(t):
    t1 = t[0]
    t2 = t[1]

    s = str(t1[0]) + "," + str(t2[0]) + "," + str(t2[0]) + "," + str(t2[1])
    return s
'''    
def construct_2darray(seg,p):
    Matrix = [[0 for x in xrange(2)] for x in xrange(2)]
    Matrix[0][0] = seg.getp1().getX() - p.getX()
    Matrix[0][1] = seg.getp1().getY() - p.getY()
    Matrix[1][0] = seg.getp2().getX() - p.getX()
    Matrix[1][1] = seg.getp2().getY() - p.getY()
    return Matrix
    
def compute_determinant(arr2d):
    ans = arr2d[0][0] * arr2d[1][1] - arr2d[1][0] * arr2d[0][1]
    return ans

class Point(object):
    
    def __init__(self,x,y):
	self.x = x
	self.y = y
    
    def __repr__(self):
	s = "(" + str(self.x) + "," + str(self.y) +")"
	return s
    def setX(self,x):
	self.x = x

    def setY(self,y):
	self.y = y

    def getX(self):
	return self.x
    
    def getY(self):
	return self.y
class Segment(object):
    
    def __init__(self,p1,p2):
	self.p1 = p1
	self.p2 = p2
    
    def getp1(self):
	return self.p1
    
    def getp2(self):
	return self.p2

    def setp1(self,p1):
	self.p1 = p1

    def setp2(self,p2):
	self.p2 = p2

    def __repr__(self):
	return str((self.p1,self.p2))

    
    def doIntersect(self,seg):
	arr2d1 = construct_2darray(self,seg.getp1())
	sign1  = compute_determinant(arr2d1)
	arr2d2 = construct_2darray(self,seg.getp2())
	sign2 = compute_determinant(arr2d2)

	if sign1 * sign2 <= 0:
	    return True
	else:
	    return False
def createSegment(seg):
    ls = seg.split(",")
    p1 = Point(0,0)
    p2 = Point(0,0)

    p1.setX(int(ls[0]))
    p1.setY(int(ls[1]))

    p2.setX(int(ls[2]))
    p2.setY(int(ls[3]))
    
    return Segment(p1,p2)

def intersecting_segments(segments):
    seg = []
    d = dict()
    dd = dict()

    for x in segments:
	se = createSegment(x)
	seg.append(se)
	d[se] = 0
    '''
    arr2d = [
		[1,2],
		[3,4]
	    ]

    compute_determinant(arr2d)
    '''
    for i in range(len(seg)):
	c = 0
	for j in range(i+1,len(seg)):
	    if(seg[i].doIntersect(seg[j])):
		d[seg[i]] += 1
		d[seg[j]] += 1
	
    for x in d: 
	dd[str(x)] = d[x]

    for x in segments:
	print dd[str(createSegment(x))]
	
    
intersecting_segments(['1,1,2,5', '1,1,5,4', '5,4,6,1', '6,1,1,1', '2,5,5,4'])
