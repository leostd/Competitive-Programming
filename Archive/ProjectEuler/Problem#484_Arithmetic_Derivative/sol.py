
# Python 3 Program to find the nth square free number
import sys
from math import sqrt 
sys.setrecursionlimit(15000)

primes = []
isPrime = []
ans = 0

def sqr(x):
    return x*x

# def primeFactorization(x):
#     cur = 0
#     fact = []
#     while(x > 1):
#         cnt = 0
#         while(x % primes[cur]):
#             cnt = cnt +1
        


# Function to count integers upto k which are having
# perfect squares as factors. i is index of next
# prime number whose square needs to be checked.
# curr is current number whos square to be checked.
# def countSquares(i, cur, k):
 
    # variable to store square of prime
    square = primes[i]*primes[i]
    newCur = square*cur
 
    # If value of greatest integer becomes zero
    if (newCur > k):
        return 0
 
    # Applying inclusion-exclusion principle
 
    # Counting integers with squares as factor
    cnt = k//(newCur)
 
    # Inclusion (Recur for next prime number)
    tmp = countSquares(i + 1, cur, k)
 
    cnt += tmp
     
    # Exclusion (Recur for next prime number)
    tmp = countSquares(i + 1, newCur, k)
    cnt -= tmp
     
    # Final count
    return cnt
 
def Mobius(n):
    prime = [1] * (n + 1)
    mobius = [1] * (n + 1)

    for i in range(2, n + 1):
        if not prime[i]:
            continue
        mobius[i] = -1
        for j in range(2, n // i + 1):
            prime[i * j] = 0
            mobius[i * j] *= -1
        for j in range(1, n // (i * i) + 1):
            mobius[j * i * i] = 0
    return mobius

def square_free(n):
    sq = int(sqrt(n))
    mobius = Mobius(sq)

    s = 0
    for i in range(1, sq + 1):
        s += mobius[i] * (n // (i * i))
    return s

def efficient_square_free(N, Imax):
    D = int(sqrt(N / Imax))
    mobius = Mobius(D)

    # compute S1
    s1 = 0
    for i in range(1, D + 1):
        s1 += mobius[i] * (N // (i * i))

    # compute M(d), d = 1, ..., D
    M_list = [0]
    M = 0
    for m in mobius[1:]:
        M += m
        M_list.append(M)

    # compute M(sqrt(n / i)), i = Imax - 1, ..., 1
    Mxi_list = []
    Mxi_sum = 0
    for i in range(Imax - 1, 0, -1):
        Mxi = 1
        xi = int(sqrt(N // i))

        sqd = int(sqrt(xi))
        # sqd < D <= xi
        for j in range(1, xi // (sqd + 1) + 1):
            Mxi -= (xi // j - xi // (j + 1)) * M_list[j]

        for j in range(2, sqd + 1):
            if xi // j <= D:
                Mxi -= M_list[xi // j]
            else:
                Mxi -= Mxi_list[Imax - j * j * i - 1]

        Mxi_list.append(Mxi)
        Mxi_sum += Mxi

    # compute S2
    s2 = Mxi_sum - (Imax - 1) * M_list[-1]
    return s1 + s2

def squarefree_numbers(n):
    counter = 0
    

def sieve(n):
    isPrime = [True] * (n+1)
    isPrime[0] = isPrime[1] = False
    for x in range(2, n+1):
        if (isPrime[x]):
            primes.append(x)
            for y in range(x+x, n+1, x):
                isPrime[y] = 0

def main():
    n = 10**6
    print(n)
    sieve(n)
    # print(primes)
    ans = square_free(10**4)
    print(ans)

if __name__ == "__main__":
    main()