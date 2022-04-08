import random as rand
N = int(5*1e5)

print(N)
for _ in range(N):
  print(rand.randint(1, 1e9), sep=' ', end=' ')

