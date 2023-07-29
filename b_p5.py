import sys

k=int(sys.stdin.readline())

stack=[]
for i in range(k):
    com=int(sys.stdin.readline())
    if com==0:
        stack.pop()
    else:
        stack.append(com)
result=0
for i in stack:
    result+=i

print(result)