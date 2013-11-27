import sys
import os

os.system('./rmx 1 inp.txt > a1.txt')
os.system('./rmx  3 inp.txt > a2.txt')
os.system('./rmx 2 inp.txt > a3.txt')
os.system('./rmx 1 inp1.txt > a4.txt')
os.system('./rmx 3 inp1.txt > a5.txt')

os.system("diff a1.txt a_test1.txt")
os.system("diff a2.txt a_test2.txt")
os.system("diff a3.txt a_test3.txt")
os.system("diff a4.txt a_test4.txt")
os.system("diff a5.txt a_test5.txt")
