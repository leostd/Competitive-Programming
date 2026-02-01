def computeGCD(x, y):
  
   while(y):
       x, y = y, x % y
  
   return x

n, m = map(int, input().split())
mul = 1
nums = list(map(int,input().strip().split()))[:n]
for i in range(n):
  mul = mul * nums[i]

ans = []
for i in range(1, m+1):
  if computeGCD(mul, i) == 1:
    ans.append(i)

print(len(ans))
for i in range(len(ans)):
  print(ans[i])
