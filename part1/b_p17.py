import sys

k,n=map(int,sys.stdin.readline().split())

data=[]
for i in range(k):
    data.append(int(sys.stdin.readline()))
start=1
end=max(data)

result=0
while(start<=end):
    mid=(start+end)//2
    total = 0
    for x in data:
            total+=(x//mid)
    if total>=n:
        start=mid+1
    else:
        end=mid-1

print(end)