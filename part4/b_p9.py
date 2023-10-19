import sys

li=[list(map(int,sys.stdin.readline().split()))for _ in range(9)]
m=max(map(max,li))

print(m)
for i in range(9):
    for j in range(9):
        if li[i][j]==m:
            print(str(i+1)+" "+str(j+1))


