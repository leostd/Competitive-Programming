import sys
nums = list(map(int, sys.stdin.read().strip().split()))
print(nums)

blinks = 75
for _ in range(blinks):
    nnums = []
    for x in nums:
        if x == 0:
            nnums.append(1)
        elif len(str(x)) % 2 == 0:
            sx = str(x)
            mid = len(sx)//2
            l = sx[:mid]
            r = sx[mid:]
            nnums.append(int(l))
            nnums.append(int(r))
        else:
            nnums.append(x*2024)
        nums = nnums

print(len(nums))
            
