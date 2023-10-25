import math
import sys

n=int(sys.stdin.readline())
li=[0 for _ in range(16)]
a=1
b=2

for i in range(1,16):
    b+=a
    li[i]=pow(b,2)
    a*=2
print(li[n])

