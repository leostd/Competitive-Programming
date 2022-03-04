def f(x):
  ret = 1
  for y in range(1, x+1):
    ret = ret * y
  return ret


x = int(input())
print(x)
print(f(x))
print(f(x) // 10)