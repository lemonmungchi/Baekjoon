import sys

n = int(sys.stdin.readline())
zoom = []

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    zoom.append([x, y])
zoom = sorted(zoom, key=lambda x: (x[1],x[0]))
end_time = 0
cnt=0

for x, y in zoom:
    if x >= end_time:
        cnt+=1
        end_time=y

print(cnt)
