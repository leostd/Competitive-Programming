import random as rand

N = 100
C = 300

max_si = int(1e15)
max_ci = 1000

print("{} {}".format(N, C))
for _ in range(N):
  print(rand.randint(1, max_si)),

print('')

for _ in range(N):
  print(rand.randint(1, max_ci)),
