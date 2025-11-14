import random as rand
t = 10

print(t)
for _ in range(t):
    n = rand.randint(1, 10)
    print(n)
    a = []
    for _ in range(n):
        x = rand.randint(0, 5)
        a.append(x)
    print(*a, sep=' ')
        
