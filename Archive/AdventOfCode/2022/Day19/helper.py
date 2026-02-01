a = [9, 0, 1, 4, 1, 10, 0, 5, 15, 3, 0, 1, 2, 0, 1, 2, 2, 8, 0, 13, 5, 7, 1, 7, 3, 1, 12, 6, 3, 1]
n = len(a)
ans = 0
for i in range(n):
    ans = ans + (i+1) * a[i]

print(ans)
