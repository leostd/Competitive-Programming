import math as m
import random as rand

n=300000
mxx = 100000
print(n)
print(mxx)

for _ in range(n):
    print(rand.randint(1,mxx))

# mxx = l + f
for _ in range(mxx):
    l = rand.randint(1, mxx)
    print("{} {} {}".format(l, rand.randint(1, mxx), rand.randint(1, mxx-l+1)))

