from numpy.random import permutation
from random import randint, choices
from os import system
import sys

def gen():
    sys.stdout = open("in","w")
    
    print(1)
    n = randint(1, 5)
    print(n)
    arr = []
    vis = set()
    for _ in range(n):
        x = randint(-20, 20);
        while abs(x) in vis:
            x = randint(-20, 20)
        vis.add(abs(x))
        arr.append(x)
    
    print(' '.join(str(x) for x in arr))
    sys.stdout = sys.__stdout__


it=100	
for _ in range(it):
    gen()
    system("./me<in>o")
    system("./he<in>o2")
    
    x=open("o", "r").read().strip()
    y=open("o2", "r").read().strip()
    
    if x != y:
        print("FAILED!!!")
        exit(0)
    
    print("OK", _+1)
