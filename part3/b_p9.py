import sys

n,m=map(int,sys.stdin.readline().split())

list=[]
for i in range(n+1):
    list.append(i)
for _ in range(m):
    i,j=map(int,sys.stdin.readline().split())
    temp=list[i]
    list[i]=list[j]
    list[j]=temp
for i in range(1,n+1):
    print(list[i],end=' ')