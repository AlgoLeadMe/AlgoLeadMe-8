from collections import deque
import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
arr = [[0 for i in range(n)] for i in range(n)]

for i in range(m):
  a,b = map(int,input().split()) 
  arr[a-1][b-1] = 1 # 노드 저장
  arr[b-1][a-1] = 1
visited = [0 for i in range(len(arr))]

def bfs(start):
  q = deque()
  q.append(start)
  visited[start] = 1
  while q:
    top = q.popleft()
    for i in range(len(arr)):
      if arr[top][i] == 1 and visited[i] == 0:
        visited[i] = visited[top]+1
        q.append(i)

bfs(0)
re = 0
for i in visited:
  if i==2 or i==3:
    re+=1
print(re)