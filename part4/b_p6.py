import sys

n=str(sys.stdin.readline().rstrip())

sum=0
for x in n:
    if(ord(x)<=67):
        sum+=2
    elif(ord(x)<=70):
        sum+=3
    elif(ord(x)<=73):
        sum+=4
    elif(ord(x)<=76):
        sum+=5
    elif (ord(x) <= 79):
        sum+=6
    elif (ord(x) <= 83):
        sum+=7
    elif (ord(x) <= 86):
        sum+=8
    elif (ord(x) <= 90):
        sum+=9
sum+=len(n)
print(sum)