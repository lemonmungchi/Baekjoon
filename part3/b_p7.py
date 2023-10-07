import sys

list=[]
for i in range(9):
    x=int(sys.stdin.readline())
    list.append(x)
print(max(list))
print(list.index(max(list))+1)