import random
def fpow(a, e, m):
	x = 1
	y = a%m
	while(e > 0):
		if(e % 2 == 1): x = (x*y)%m
		y = (y*y)%m
		e //= 2
	return x
def gcd(a, b):
	if(b == 0):
		return a
	else:
		if(a == 0):
			return b
		else:
			return gcd(b, a%b)
def primetest(n, k):
	if(n == 1): return False
	if(n == 2 or n == 3): return True
	if(n % 2 == 0): return False
	r = 0
	d = n-1
	while(d % 2 == 0):
		r+=1
		d = d//2
	for i in range(0, k):
		a = random.randrange(2, n-1)
		x = fpow(a, d, n)
		if(x == 1 or x == n-1): continue
		compo = True
		for j in range(0, r-1):
			x = fpow(x, 2, n)
			if(x == 1): return False
			if(x == n-1):
				compo = False
				break
		if(compo): return False
	return True
def f(x, c, n):
	return ((x*x + c)%n)
def PollardRho(N):
        if N%2==0:
                return 2
        y,c,m = random.randint(1, N-1),random.randint(1, N-1),random.randint(1, N-1)
        g,r,q = 1,1,1
        while g==1:             
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if g==N:
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break
         
        return g
def factors(n, pf):
	P = primetest(n, 2)
	i = 2
	x = n
	if(P == False): 
		while(x == n):
			x = PollardRho(n)
	if(x == n):
		pf.append(x)
	else:
		factors(n//x, pf)
		factors(x, pf)
t = int(input())
while(t > 0):
	t-=1
	n = int(input())
	pf = []
	factors(n, pf)
	pf.sort()
	m = len(pf)
	for i in range(0, m):
		if(i < m - 1):
			print(pf[i]),
		else: print(pf[i])