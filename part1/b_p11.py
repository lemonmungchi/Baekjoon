import sys

n=int(sys.stdin.readline())

array=[]
for i in range(n):
    x=int(sys.stdin.readline().rstrip())
    array.append(x)

array.sort()
for i in array:
    print(i)