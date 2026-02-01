import random as r

a = 10

maxn = 100
maxk = 100
maxai = 100


print(a)
for i in range(0, a):
    n = r.randint(1,maxn)
    t = r.randint(0, maxk)
    print("{} {}".format(n, t))
    for i in range(0, n):
        print(r.randint(0, maxai)),


