import random as rand

MAXN = 10000

nacum = 0

while nacum < MAXN:
  N = rand.randint(1, MAXN)
  Y = 1e9
  while(Y > 100_000 or Y > N*N):
    Y = rand.randint(1, min(N*N, 100_000))
  print("{} {}".format(N, Y))
  nacum += N
  visited = set()
  while(len(visited) < Y):
    r = rand.randint(1, N)
    c = rand.randint(1, N)
    if (r, c) in visited:
      continue
    else:
      visited.add((r, c))
    print("{} {}".format(r, c))

