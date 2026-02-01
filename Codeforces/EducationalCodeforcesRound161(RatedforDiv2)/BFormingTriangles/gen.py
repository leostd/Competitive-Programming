import random as rand

N = 10

print(N)
for _ in range(N):
    n = rand.randint(1, 20)
    for _ in range(n):
        print(rand.randint(1, n))
