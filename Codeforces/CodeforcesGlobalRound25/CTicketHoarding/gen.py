import random as rand
t = 1
print(t)
for _ in range(t):
    n = rand.randint(1, 10)
    m = rand.randint(1, 10**2)
    k = min(n*m, 10**2)
    print(f"{n} {m} {k}")
    for _ in range(n):
        x = rand.randint(1, 10**2)
        print(x),
    print("\n")

