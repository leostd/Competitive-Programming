import random

random.seed(1)

mark = set()

for i in range(1, 10000):
    x = random.randint(1, 2**32-1)
    if x not in mark:
        mark.add(x)
    print(x)
print(0)