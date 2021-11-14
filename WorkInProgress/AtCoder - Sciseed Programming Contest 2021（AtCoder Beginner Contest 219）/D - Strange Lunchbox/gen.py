import random as rand

N = rand.randint(1, 300)
X = rand.randint(1, 300)
Y = rand.randint(1, 300)


print(N)
print("{} {}".format(X, Y))
for _ in range(0, N):
  print("{} {}".format(rand.randint(1, 2), rand.randint(1, 2)))
