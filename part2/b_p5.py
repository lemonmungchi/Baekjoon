import sys

a=str(sys.stdin.readline().rstrip())
b=str(sys.stdin.readline().rstrip())

print(int(a)*int(b[len(b)-1]))
print(int(a)*int(b[len(b)-2]))
print(int(a)*int(b[len(b)-3]))
print(int(a)*int(b))