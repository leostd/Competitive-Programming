N = 5 * 10**15
primes[5000000], LMT = 71000000, top
up[5000000]
ans = 0

P = _.primes(LMT)
for p in P :
    top += 1
    primes[top] = p
    up[top] = N/p/p

def  f( x,  e,  p) :
    if e % p == 0 :
        return x
    return x/p

def dfs( d,  cur,  g) :
    if g == 0 :
        return 
    print(cur, g)
    global ans
    
    i, p, e
    t, x, S = N/cur

    ans += S * g
    for i in range(d + 1, top) :
        if up[i] < cur :
            break
        p = primes[i]
        e = 0
        x = 1
        while x * p <= S :
            x *= p
            e += 1
            if e >= 2 :
                dfs(i, cur * x, g * (f(x, e, p) - f(x/p, e - 1, p)))

dfs(0, 1, 1)

print(ans)
