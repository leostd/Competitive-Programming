n = input()

a = map(long, raw_input().split())

acum = 1

z = 0
for x in a:
    z = z + (x == 0)
    acum = acum * x
    if z:
        acum = 0
        break

if acum > 1000000000000000000:
    print(-1)
else:
    print(acum)