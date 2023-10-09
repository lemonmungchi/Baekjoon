import sys

list=[]
for i in range(30):
    list.append(0)
for i in range(28):
   n=int(sys.stdin.readline())
   list[n-1]=1
for i in range(30):
    if(list[i]==0):
        print(i+1)
