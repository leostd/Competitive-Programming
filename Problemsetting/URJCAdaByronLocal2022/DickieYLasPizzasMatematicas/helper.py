def factorial(x):
  ret = 1
  for i in range(1, x+1):
    ret = ret * i
  return ret

def binom_coefficient(n, k):
  num = factorial(n)
  denom = factorial(n-k) * factorial(k)
  return num // denom

def cat(n):
  num = factorial(2*n)
  denom = factorial(n) * factorial(n+1)
  return num // denom

MOD = 1009

a = input()

print(cat(a))
print(cat(a) % MOD)
print(cat(a+MOD) % MOD)
