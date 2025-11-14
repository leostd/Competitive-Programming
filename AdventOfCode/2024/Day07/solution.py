import sys

input = []

def f(i, j, cur):
    if j >= len(input[i]):
        return cur == input[i][0]

    a = cur * input[i][j]
    b = cur + input[i][j]
    c = int(str(cur)+str(input[i][j]))

    return f(i, j+1, a) or f(i, j+1, b) or f(i, j+1, c)

for line in sys.stdin:
    for i in range(len(line)):
        nums = list(map(int, line.replace(":", "").split()))
    input.append(nums)

ans = 0
for i in range(len(input)):
    if f(i, 2, input[i][1]):
        ans += input[i][0]

print(ans)


