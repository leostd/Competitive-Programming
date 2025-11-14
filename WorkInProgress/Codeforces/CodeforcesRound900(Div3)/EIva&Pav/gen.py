import random as rand

TC = 5
N = 20
Q = 10
MAX_AI = 2**30;

print(TC)
for _ in range(TC):
    print(N)
    for _ in range(N):
        x = rand.randint(1, MAX_AI);
        print(x),
    
    print(Q)
    for _ in range(Q):
        l = rand.randint(1, N)
        k = rand.randint(1, MAX_AI)
        print("{} {}".format(l, k))
