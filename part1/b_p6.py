from sys import stdin,setrecursionlimit
setrecursionlimit(10**5)

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

def dfs(graph,v,visited):
    global c
    visited[v]=c
    for i in graph[v]:
        if visited[i]==0:
            c+=1
            dfs(graph,i,visited)

dfs(graph, r, visited)

for i in range(1,n+1):
    print(visited[i])