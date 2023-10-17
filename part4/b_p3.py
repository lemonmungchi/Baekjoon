import sys

n=int(sys.stdin.readline())

for _ in range(n):
    r,s=map(str,sys.stdin.readline().rstrip().split())
    for i in range(len(s)):
        for j in range(int(r)):
            print(s[i],end='')
    print()