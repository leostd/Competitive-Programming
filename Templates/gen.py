import random as rand
import sys

abc = "abcdefghijklmnopqrstuvwxyz"
ABC = abc.upper()
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
dxKn = [-2, -1, 1, 2,  2,  1, -1, -2]
dyKn = [ 1,  2, 2, 1, -1, -2, -2, -1]
dxK = [0, 0, 1, -1, 1, 1, -1, -1]
dyK = [1, -1, 0, 0, 1, -1, 1, -1]
 
MOD = (1e9) + 7
INF = (1e9) + 100
INF64 = 2e18
PI = (3.1415926535897932384626433832795)
e = (2.7182818284590452353602874713527)
EPS = 1e-9

# Reads two numbers from input and typecasts them to int using 
# list comprehension
# x, y = [int(x) for x in input().split()]  
# Reads two numbers from input and typecasts them to int using 
# map function
# x, y = map(int, input().split())

testcases = int(sys.argv[0])

# Recall to consider max and min values
# Usually 0 and 1 are minimum values
MAXN = 1e5
MAXM = 1e5
MAXV = 1e9
MINN = 1
MINM = 1
MINV = 0

def gen_testcase():
    n = rand.randint(MINN, MAXN)

def gen_cornercase():
    n = MINN
    # n = MAXN
    m = MINM
    # m = MAXM

# for _ in range(testcases)
#     gen_testcase()

gen_cornercase()

