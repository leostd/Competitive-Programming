import random as rand
import sys
N_TESTCASES = 100

def testcase(num):
  filename = "./testcases/rand_small_{}.in".format(100+num)
  sys.stdout = open(filename, 'w')
  t = rand.randint(1, 100)
  print(t)
  while t >= 0:
    print(rand.randint(1, 10**5))
    t = t-1

for T in range(N_TESTCASES):
  testcase(T)