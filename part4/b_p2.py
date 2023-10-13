import sys

s=str(sys.stdin.readline().rstrip())
for i in 'abcdefghijklmnopqrstuvwxyz':
    print(s.find(i),end=' ')