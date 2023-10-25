import sys

t=int(sys.stdin.readline())
qu=[25,10,5,1]
li=[[0 for _ in range(len(qu))]for _ in range(t)]

for i in range(t):
    c=int(sys.stdin.readline())
    for j in range(len(qu)):
        li[i][j],c=divmod(c,qu[j])

for i in range(t):
    for j in range(len(qu)):
        print(li[i][j],end=' ')
    print()
