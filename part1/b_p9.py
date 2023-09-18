import sys

data=[]
len=5
for i in range(len):
    x=int(sys.stdin.readline())
    data.append(x)
data.sort()
avg=0

for i in range(len):
    avg+=data[i]
print(int(avg/len))
print(int(data[2]))
