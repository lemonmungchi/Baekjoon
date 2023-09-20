import sys

a,b=map(int,sys.stdin.readline().split())
c=int(sys.stdin.readline())

if(b+c>=60):
    a+=(b+c)//60
    if(a>23):
        print(str(a-24)+" "+str((b+c)%60))
    else:
        print(str(a)+" "+str((b+c)%60))
else:
    print(str(a)+" "+str(b+c))


