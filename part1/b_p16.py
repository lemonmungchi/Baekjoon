import sys

a=int(sys.stdin.readline())
nl = list(map(int, sys.stdin.readline().split()))
b=int(sys.stdin.readline())
ml = list(map(int, sys.stdin.readline().split()))

data={}

for n in nl:

    if n in data:
        data[n] += 1
    else:
        data[n] = 1

print(' '.join(str(data[m]) if m in data else '0' for m in ml))