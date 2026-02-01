from numpy.random import permutation
from random import randint, choices
from os import system
import sys

def gen():
    sys.stdout = open("in","w")
    
    # Print output
    
    print(1)
    n = randint(1, 10)
    k = randint(0, n-1)
    a = []
    print(f"{n} {k}")
    for i in range(n):
        a.append(randint(1, n))
    print(' '.join(map(str, a)))
    sys.stdout = sys.__stdout__


it=10	
for _ in range(it):
    gen()
   # system("./me<in>o")
    system("./he<in")
    
    #x=open("o", "r").read().strip()
    #y=open("o2", "r").read().strip()
    
    #if x != y:
    #    print("FAILED!!!")
    #    exit(0)
    
    #print("OK", _+1)
