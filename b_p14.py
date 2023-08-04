from sys import stdin,setrecursionlimit
setrecursionlimit(10**5)
from collections import deque

n,m,r=map(int,stdin.readline().split())

graph=[[] for _ in range(n+1)]
visited=[0]*(n+1)
result=[]

c=1
for i in range(m):
    x,y=map(int,stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)
for i in range(n+1):
    graph[i].sort()

def bfs(v,e,r):
    queue=deque([e])
    r[e]=1
    count=2

    while queue:
        e=queue.popleft()

        for i in v[e]:
            if visited[i]==0:
                queue.append(i)
                r[i]=count
                count+=1
bfs(graph,r,visited)

for i in visited[1::]:
    print(i)
