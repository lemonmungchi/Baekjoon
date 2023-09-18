import sys

n,m=map(int,sys.stdin.readline().split())

data=list(map(int,sys.stdin.readline().split()))

start=1
end=max(data)

result=0
while(start<=end):
    mid=(start+end)//2
    total = 0
    for x in data:
        if x>mid:
            total+=(x-mid)
    if total>=m:
        start=mid+1
    else:
        end=mid-1

print(end)
