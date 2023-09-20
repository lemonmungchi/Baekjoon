import sys

h,m=map(int,sys.stdin.readline().split())

if(m<45):
    if(h==0):
        print("23 "+str(m+15))
    else:
        print(str(h-1)+" "+str(m+15))
else:
    print(str(h)+" "+str(m-45))