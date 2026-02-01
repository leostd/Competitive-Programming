import random as rand

n = 10
m = 10

print("{} {}".format(n, m))

vvis = set()
v = 1
for i in range(1, n+1):
    print(v)
    v += i

hvis = set()
for i in range(m):
    x1, x2, y = (1, rand.randint(1, 10**9), rand.randint(1, 10**9))
    if  (x2, y) in hvis:
        continue
    print("{} {} {}".format(x1, x2, y))
    hvis.add((x2, y))


