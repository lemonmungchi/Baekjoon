import sys

a=int(sys.stdin.readline())

if a>=90 and a<=100:
    print("A")
elif a<=89 and a>=80:
    print("B")
elif a<=79 and a>=70:
    print("C")
elif a<=69 and a>=60:
    print("D")
else:
    print("F")