import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline

INF = int(1e9)
n = int(input())
m = int(input())
graph = defaultdict(list)

# 입력
for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))

v1,v2 = map(int,input().split())

distance = [INF] * (n+1)
prev_node = [0] * (n+1)
# 데이크 스트라 알고리즘
def di(start):
    q = []
    heapq.heappush(q, [0,start])
    distance[start] = 0

    while q:
        dist, node = heapq.heappop(q)

        if distance[node] < dist:
            continue
        for n,w in graph[node]:
            cost = dist + w

            if distance[n] > cost:
                distance[n]= cost
                prev_node[n] = node
                heapq.heappush(q,[cost,n])

di(v1)
print(distance[v2])

path = [v2]
now = v2
while now != v1:
  now = prev_node[now]
  path.append(now)

path.reverse()
print(len(path))
print(' '.join(map(str,path)))