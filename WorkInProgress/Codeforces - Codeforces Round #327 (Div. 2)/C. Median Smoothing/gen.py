N = 100
cur = 1
s = []
print(N)
for _ in range(N):
  s.append(cur)
  cur = abs(cur-1)

for i in range(N):
  print(s[i], end=' '),