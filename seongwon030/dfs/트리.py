import sys
input = sys.stdin.readline

n = int(input())
k = list(map(int,input().split()))
del_node = int(input())

def dfs(node):
  k[node] = -2
  for i in range(n):
    if node == k[i]:
      dfs(i)

dfs(del_node)

cnt = 0
for j in range(n):
  if k[j] != -2 and j not in k:
    cnt+=1

print(cnt)