from collections import deque

n = int(input())
k = list(map(int,input().split()))

cur, jump = 0,0
queue = deque()
queue.append((cur,jump))  # 현재 인덱스, 점프 횟수
visited = [] 

while queue:
  cur, jump = queue.popleft()
  if cur == len(k)-1:   # 현재 인덱스가 마지막 칸에 해당하면 jump 수 출력 후 종료
    print(jump)
    exit()

  for i in range(1, k[cur]+1):  # k안에 있는 숫자 이하만큼 오른쪽으로 점프 가능
    next = cur + i              # 다음 인덱스는 현재 인덱스 + i 
    if next not in visited:     # 방문 안 했으면 다음 인덱스와 점프수 1을 더한 것 큐에 추가
      queue.append((next, jump+1))
      visited.append(next)      # 다음 인덱스 방문 처리

print(-1) # 중간에 exit 안하면 -1 출력