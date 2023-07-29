import sys

n=int(sys.stdin.readline())
n_data=set(map(int,sys.stdin.readline().split()))

a=int(sys.stdin.readline())
a_data=list(map(int,sys.stdin.readline().split()))

for i in range(a):
    if a_data[i] in n_data:
        print("1")
    else:
        print("0")