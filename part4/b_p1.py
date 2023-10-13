import sys

n=int(sys.stdin.readline())
x=str(sys.stdin.readline().rstrip())
sum=0
for i in range(n):
    sum+=int(x[i])
print(sum)