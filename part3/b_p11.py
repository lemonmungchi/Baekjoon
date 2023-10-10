import sys

list=[]

for i in range(10):
    x=int(sys.stdin.readline())
    if x%42 not in list:
        list.append(x%42)

print(len(list))



