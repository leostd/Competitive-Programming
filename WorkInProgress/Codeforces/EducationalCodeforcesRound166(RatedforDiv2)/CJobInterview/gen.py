import random as rand 

t = 5

print(t)
for _ in range(t):
    n = rand.randint(0, 4)
    m = rand.randint(0, 4)
    print(f"{n} {m}")
    a = []
    b = []
    for _ in range(n + m + 1):
        x = rand.randint(1, 10)
        y = rand.randint(1, 10)
        while(y == x):
            y = rand.randint(1, 10)
        a.append(x)
        b.append(y)
    print(*a)
    print(*b)



