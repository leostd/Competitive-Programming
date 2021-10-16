import random

t = 10**5

print(t)
for _ in range(t):
    n = random.randint(1, 10**9)
    a = random.randint(1, 10**3)
    b = random.randint(1, 10**3)
    print("{} {} {}".format(n, a, b))
