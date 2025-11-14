from numpy.random import permutation
from random import randint, choices
from os import system
import sys

def gen():
	sys.stdout = open("in","w")
	
	# Print output
    n = randint(3, 10
	print())
    print(generateRandomString())
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
