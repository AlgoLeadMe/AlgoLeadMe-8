from collections import deque
import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]

n,m = map(int,input().split())
k = []
for i in range(n):
  k.append(list(input().rstrip()))

visited = [[False]*m for _ in range(n)] # 방문여부
dp = [[0]*m for _ in range(n)]

ans = 0
def dfs(x,y,cnt):
  global ans
  ans = max(ans, cnt)
  for i in range(4):
    nx = x + int(k[x][y]) * dx[i]
    ny = y + int(k[x][y]) * dy[i]
    if 0 <= nx < n and 0 <= ny < m and k[nx][ny] != 'H' and cnt+1 > dp[nx][ny]:
      if visited[nx][ny]:
        print(-1)
        exit()
      else:
        dp[nx][ny] = cnt+1
        visited[nx][ny] = True
        dfs(nx,ny,cnt+1)
        visited[nx][ny] = False

dfs(0,0,0)
print(ans+1)