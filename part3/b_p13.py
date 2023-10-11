import sys

n=int(sys.stdin.readline())
list=list(map(int,sys.stdin.readline().split()))
m=max(list)
for i in range(n):
    list[i]=list[i]/m*100
sum=0
for i in range(n):
    sum+=list[i]
avg=sum/float(n)
print(avg)
