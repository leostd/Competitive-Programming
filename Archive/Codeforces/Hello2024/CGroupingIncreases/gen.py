from numpy.random import permutation
from random import randint, choices
from os import system
import sys

def gen():
    sys.stdout = open("in","w")
    print(1)
    # Print output

    n = randint(5, 10)
    print(n)
    a = []
    for i in range(n):
        x = randint(1, 20)
        a.append(x)

    print(' '.join(map(str, a)))

    sys.stdout = sys.__stdout__


it=100	
while(1):
    gen()
    system("./me<in>o")
    system("./he<in>o2")
    
    x=open("o", "r").read().strip()
    y=open("o2", "r").read().strip()
    
    if x != y:
        print("FAILED!!!")
        exit(0)
    
    print("OK")
