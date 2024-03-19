from collections import deque

m,n = map(int,input().split())
tomato = [list(map(int,input().split())) for _ in range(n)]
queue = deque([]) # 좌표 -> 리스트

dx, dy = [-1,1,0,0], [0,0,-1,1] # 좌,우,하,상 -> 좌표 이동 
ans = 0 # 최소 날짜 

for i in range(n):
  for j in range(m):
    if tomato[i][j] == 1: # 1인 경우 토마토가 있으므로 큐에 append
      queue.append([i,j])

def bfs():
  while queue:
    x,y = queue.popleft() # 첫 번째 좌표 
    for i in range(4):
      nx,ny = dx[i] + x, dy[i] + y
      # 좌표 크기를 넘어가선 안되고 값이 0이어야 
      if 0 <= nx < n and 0 <= ny < m and tomato[nx][ny] == 0:
        tomato[nx][ny] = tomato[x][y] + 1 # 그 다음 칸으로 이동
        queue.append([nx,ny])

bfs()
flag = False # 안 익은 토마토 있는지

for i in tomato:
  if 0 in i:
    flag = True
    break

if flag: # 안 익은 토마토가 존재하므로 -1출력
  print(-1)
else:
  for i in tomato:
    ans = max(ans,max(i))
  print(ans-1)

