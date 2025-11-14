from numpy.random import permutation
from random import randint, choices, shuffle, sample
from os import system
import sys

def gen():
    sys.stdout = open("in","w")
    
    # Print output
    
    print(1)
    #n = randint(1, 1000)

    n = 100_000 
    a = sample(range(n), n)
    b = sample(range(n), n)

    
    print(n)
    print(' '.join(map(str, a)))
    print(' '.join(map(str, b)))

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
