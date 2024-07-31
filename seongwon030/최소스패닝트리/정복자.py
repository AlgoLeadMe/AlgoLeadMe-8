import collections
import sys
from heapq import heappop, heappush

input = sys.stdin.readline

N,M,T = map(int,input().split())
graph = collections.defaultdict(list)
answer = 0
conquer_cost = 0

for _ in range(M):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

visited=[False for _ in range(N+1)]
heap=[(0,1)]

while heap:
    cost,node = heappop(heap) # 힙에서 최소비용 간선 꺼냄

    if not visited[node]: # 해당 노드 방문되지 않았다면 방문처리
        visited[node]=True
        answer += (cost + conquer_cost)  # answer에 현재 간선 비용과 T의 합을 더해줌

        if node!=1: # 첫 번째 노드 아니면, 정복비용 T 증가 
            conquer_cost += T

        for next_node,next_cost in graph[node]: # 다음 노드 탐색하여 힙에 넣기 
            if not visited[next_node]:
                heappush(heap,(next_cost,next_node))


print(answer)