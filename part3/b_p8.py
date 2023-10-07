import sys

n,m=map(int,sys.stdin.readline().split())
list=[]
for i in range(n+1):
    list.append(0)
for x in range(m):
    i,j,k=map(int,sys.stdin.readline().split())
    for x in range(i,j+1):
        list[x]=k
for i in range(1,n+1):
    print(list[i],end=' ')