import sys

n=int(sys.stdin.readline())

data=list(map(int,sys.stdin.readline().split()))
data.sort()

result=0
temp=0

for i in range(n):
   result+=(data[i]+temp)
   temp+=data[i]

print(result)