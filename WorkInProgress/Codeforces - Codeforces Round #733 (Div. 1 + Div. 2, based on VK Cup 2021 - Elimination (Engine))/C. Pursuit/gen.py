import random as rn

t = 1
n = 5

print(t)
print(n)

for i in range(0, n):
    # print(rn.randint(0, 100), sep=' ', end=' '),
    print(0, end=' ')
print('\n')
for i in range(0, n):
    print(rn.randint(0, 100), sep=' ', end=' '),