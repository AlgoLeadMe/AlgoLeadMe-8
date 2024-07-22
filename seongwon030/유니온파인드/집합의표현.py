import sys
input = sys.stdin.readline

n,m = map(int,input().split())
parent = [i for i in range(n+1)]

def find(x):
  if x!=parent[x]:
    parent[x] = find(parent[x])
  return parent[x]

def union(x,y):
  x,y = find(x),find(y)
  if x<y:
    parent[x] = y
  else:
    parent[y] = x

for i in range(m):
  a,b,c = list(map(int,input().split()))
  if not a:
    union(b,c)
  else:
    if find(b) == find(c):
      print("YES")
    else:
      print("NO")