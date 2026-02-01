from random import randint, choices
from os import system
import sys


def gen():
    sys.stdout = open("in", "w")

    # Print output
    maxlen = 15
    maxdays = 100

    len = randint(1, maxlen)
    days = randint(1, maxdays)
    base = randint(1, len)

    print(1)
    print("{} {} {}".format(len, days, base))

    sys.stdout = sys.__stdout__


it = 100
# for _ in range(it):
while 1:
    gen()
    system("./me<in>o")
    system("./he<in>o2")

    x = open("o", "r").read().strip()
    y = open("o2", "r").read().strip()

    if x != y:
        print("FAILED!!!")
        exit(0)

    print("OK")
