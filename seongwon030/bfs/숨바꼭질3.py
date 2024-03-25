from collections import deque
import sys

input = sys.stdin.readline

result = 0
MAX = 10**5 # 움직일 수 있는 최대좌표
dist = [-1] * (MAX + 1) # 해당 위치에 도착했을 때 시간
n, k = map(int,input().split())

q = deque()
q.append(n)
dist[n] = 0 # 시작위치를 체크하기 위해 0으로 설정
while q:
    x = q.popleft()
    if x==k: # x변수인 수빈의 위치가 동생이 있는 k와 같을 때 멈춤
      result = dist[x]
      break
    # nx = 4,6,10 (현재 위치 5일 때 이동할 수 있는 방향)
    for nx in (x*2, x-1, x+1):
      # 범위내에 있고 아직 방문안했다면
      if 0<=nx<=MAX and dist[nx] == -1: 
        if nx == x*2: # 곱하기2를 한 좌표부터 체크
          dist[nx] = dist[x]
        else:
          dist[nx] = dist[x] + 1 
        q.append(nx)
print(result)