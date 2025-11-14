import random as rand
max_n = 10
max_m = 10
max_h = 100
test_cases = 1


print(test_cases)
for i in range(test_cases):
    n = rand.randint(1, max_n)
    m = rand.randint(1, max_m)
    h = rand.randint(1, max_h)

    n = 2
    m = 100_000
    h = 1000000
    print("{} {} {}".format(n, m, h))
    for k in range(n):
        for _ in range(m):
            #tij = rand.randint(1, max_h)
            tij = k+1
            print(tij)

