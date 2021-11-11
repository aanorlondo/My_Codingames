import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

direction = input()
x = int(input())
u = "/\\"
d = "\\/"

if direction == "up" :
    for i in range(x) : 
        print (" "* (x-i-1), u*(i+1),  sep='')
else :
    for i in range(x,0,-1) :
        print (" "*(x-i) ,  d*(i),    sep='')
