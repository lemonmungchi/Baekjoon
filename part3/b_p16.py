import sys

n=int(sys.stdin.readline())
for i in range(n):
    x=str(sys.stdin.readline().rstrip())
    print(x[0]+x[len(x)-1])