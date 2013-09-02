#http://www.talentbuddy.co/challenge/518bd5c84af0110af3822d21
import math
def compute_segment_length(seg):
    ls = seg.split(",")
    p1 = []
    p2 = []
    for i in range(len(ls)):
	if(i < 2):
	    p1.append(int(ls[i]))
	else:
	    p2.append(int(ls[i])) 
    
    l = math.sqrt ( (p1[0]-p2[0]) ** 2 + (p1[1] - p2[1]) ** 2 )
    return l

def longest_street(segments):
    d = []
    for x in segments:
	d.append( compute_segment_length(x) )

    print "%0.2f" %(max(d))
longest_street(['1,1,2,5', '1,1,5,4', '5,4,6,1', '6,1,1,1', '2,5,5,4'])
