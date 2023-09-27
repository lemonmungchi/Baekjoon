import sys

n=int(sys.stdin.readline())

list=list(map(int,sys.stdin.readline().split()))

print(str(min(list))+" "+str(max(list)))