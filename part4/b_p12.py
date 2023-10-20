import sys

n=int(sys.stdin.readline())

li=[[0 for _ in range(100)]for _ in range(100)]
for i in range(n):
    x,y=map(int,sys.stdin.readline().split())
    for i in range(x,x+10):
        for j in range(y,y+10):
            li[i][j]=1
sum=0
for i in range(100):
    for j in range(100):
        if(li[i][j]==1):
            sum+=1
print(sum)