import random as rand

t = 1
n = 200000

print(t)

while t > 0:
  print(n)
  for i in range(n):
    print(rand.randint(1, n)),
  t = t - 1