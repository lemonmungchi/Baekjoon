import sys

x=int(sys.stdin.readline())
n=int(sys.stdin.readline())
sum=0
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    sum+=a*b

if x==sum:
    print("Yes")
else:
    print("No")
