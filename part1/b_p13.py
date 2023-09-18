import sys

n=sys.stdin.readline()
data=[]
for i in str(n):
    data.append(i)

data.sort(reverse=True)
for i in data:
    print(i,end='')