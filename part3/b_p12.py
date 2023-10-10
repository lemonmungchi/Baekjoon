import sys

list=[]
n,m=map(int,sys.stdin.readline().split())
for i in range(1,n+1):
    list.append(i)
for _ in range(m):
    i,j=map(int,sys.stdin.readline().split())
    list2=list[i-1:j]
    list2.reverse()
    list[i-1:j]=list2
for i in range(n):
    print(list[i],end=' ')