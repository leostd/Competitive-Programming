import random

n = 51

# a = []
# vis = set()
# while len(a) != n:
#     b = random.randint(1, n)
#     if not b in vis:
#         a.append(b)
#         vis.add(b)

a = range(1, n+1)
a.reverse()

print(n)
for x in a:
    print(x),