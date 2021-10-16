import random as rn

t = 1000


print(t)

for _ in range(0, t):
    n = rn.randint(2, 100)
    print(n)
    for i in range(0, n):
        x = i+1
        while(x == i+1 ):
            x = rn.randint(1, n)
        print(x, end=' ')
    print('\n')