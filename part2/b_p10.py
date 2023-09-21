import sys

a,b,c=map(int,sys.stdin.readline().split())

if(a==b and b==c):
    print(str(a*1000+10000))
elif(a==b or b==c or c==a):
    if(a==b):
        print(str(1000+(a*100)))
    elif(b==c):
        print(str(1000+(b*100)))
    else:
        print(str(1000 + (c * 100)))
else:
    print(str(max(a,b,c)*100))