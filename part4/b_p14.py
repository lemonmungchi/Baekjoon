import sys

n,b=map(int,sys.stdin.readline().split())
s = ''
arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

while n:
    s += str(arr[n%b])
    n //= b

print(s[::-1])