import random as rand

TC = 20
MAXN = 10
MAXLVL = 50
MAXLIFT = 100

for _ in range(TC):
  N = rand.randint(5, MAXN)
  print(N)
  MAX = rand.randint(5, MAXLIFT)
  print("{} {} {}".format(0, rand.randint(1, MAX), rand.randint(1, MAXLVL)))
  vis = set()
  for _ in range(N-2):
    a = int(1e9)
    b = 0
    while(a >= b and (a, b) not in vis):
      a = rand.randint(0, MAX)
      b = rand.randint(1, MAX)
    vis.add((a,b))
    print("{} {} {}".format(a, b, rand.randint(1, MAXLVL)))
  print("{} {} {}".format(10, MAX - 10, rand.randint(1, MAXLVL)))

