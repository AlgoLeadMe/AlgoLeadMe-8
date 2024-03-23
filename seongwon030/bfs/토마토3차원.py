from collections import deque
import sys

input = sys.stdin.readline

m,n,h = map(int,input().split())
tomato = []
for i in range(h):
  tomato.append([list(map(int,input().split())) for _ in range(n)])


queue = deque([]) # 좌표 -> 리스트
dx, dy, dz = [-1,1,0,0,0,0], [0,0,-1,1,0,0,], [0,0,0,0,-1,1] # 좌,우,하,상,아래,위 -> 좌표 이동
ans = 0 # 최소 날짜
cnt = 0

for i in range(h): # dz
  for j in range(n): # dy
    for k in range(m): # dx
      if tomato[i][j][k] == 1: # 1인 경우 토마토가 있으므로 큐에 append
        queue.append((i,j,k))


while queue:
  z,y,x = queue.popleft() # 첫 번째 좌표
  for i in range(6):
    nx,ny,nz = dx[i] + x, dy[i] + y, dz[i] + z
    # 좌표 크기를 넘어가선 안되고 값이 0이어야
    if 0 <= nx < m and 0 <= ny < n  and 0 <= nz < h and tomato[nz][ny][nx] == 0:
      tomato[nz][ny][nx] = tomato[z][y][x] + 1 # 그 다음 칸으로 이동
      queue.append((nz,ny,nx)) 
      cnt+=1

flag = False 

for i in range(h):
    for j in range(n): 
      for k in range(m): 
        if tomato[i][j][k] == 0: 
          flag = True
          break
        else:
          continue
      max_list = tomato[i][j]
      ans = max(ans, max(max_list))
      
# cnt 0이면
# 모두 익어있거나 -> flag는 False
# 익은게 없거나 (무조건 0이 하나는 존재) -> flag는 True
if cnt == 0:
  if flag:
    print(-1)
  else:
    print(0)
elif flag:
  print(-1)
else:
  print(ans-1)