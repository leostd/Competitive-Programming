N = 10**10

primes = []
isPrime = [True for _ in range(N)]

for x in range(2, N):
  if isPrime[x]:
    primes.append(x)
    y = x+x
    while y < N:
      isPrime[y] = False
      y = y + x

sz = len(primes)
for i in range(500):
  print(primes[sz-i-1])

