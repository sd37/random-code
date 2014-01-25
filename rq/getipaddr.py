import sys
import os
import time
import urllib2

while True:
    f = open("/home/spandan/Dropbox/myipaddr.txt","w")
    myip = urllib2.urlopen("http://myip.dnsdynamic.org/").read()
    f.write(time.asctime())
    f.write("\n")
    f.write(myip)
    f.write("\n")
    f.close()
    time.sleep(60*15)
