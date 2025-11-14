x = 2
k = 3
threshold = 10**18
while (x**(k+1) - 1) / (x-1) < threshold:
    k = k + 1
print(k)
