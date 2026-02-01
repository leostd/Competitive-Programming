import random as rand

TC = 1000

print(TC)
while TC > 0:
    N = rand.randint(1, 100)
    M = rand.randint(1, 200)
    K = 2

    print("{} {} {}".format(N, M, K))
    for _ in range(M):
        l = rand.randint(1, N)
        r = rand.randint(l, N)
        print("{} {}".format(l, r))
    TC = TC - 1
