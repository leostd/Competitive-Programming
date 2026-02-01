import collections
n,k = input().strip().split()
n = int(n)
k = int(k)

friends = []
for i in range(0, n):
    a,b = input().strip().split()
    a = int(a)
    b = int(b)
    friends.append([a,b])

friends = sorted(friends)
# print(friends)
f = collections.deque(friends)
# print(f)
cur = 0
while len(f) > 0:
    # print("cur: {} k: {}".format(cur, k))
    a,b = f.popleft()
    a = int(a)
    b = int(b)
    # print("a: {} b: {}".format(a, b))
    if (cur + k) >= a:
        k -= (a - cur)
        k += b
        cur = a
    else:
        break

# print("final cur: {} k: {}".format(cur, k))
print(cur+k)



