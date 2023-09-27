import sys

n,x=map(int,sys.stdin.readline().split())

list=list(map(int,sys.stdin.readline().split()))

for i in list:
    if(i<x):
        print(i,end=" ")
