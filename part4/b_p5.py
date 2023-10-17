import sys

a,b=map(str,sys.stdin.readline().rstrip().split())
c=""
d=""
for i in range(len(a),0,-1):
    c+=a[i-1]
for i in range(len(b),0,-1):
    d+=b[i-1]
if(int(c)>int(d)):
    print(c)
else:
    print(d)