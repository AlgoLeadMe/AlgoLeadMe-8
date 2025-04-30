import heapq
import sys

input = sys.stdin.readline

n,e = map(int,input().split())
graph = [[] for _ in range(n+1)]

# 입력
for _ in range(e):
    a,b,c = map(int,input().split())
    
    graph[a].append([b,c])
    graph[b].append([a,c])
    
v1 ,v2 = map(int,input().split())

# 데이크 스트라 알고리즘
def di(start,size):
    # 사용한 길 계속 사용 가능 하므로 계속 초기화 한다.
    distance = [float('inf')] * (size+1)
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
                heapq.heappush(q,[cost,n])
                
    return distance

#각각 1,v1,v2가 시작점으로 각 노드에 대한 최단 경로를 담고 있다.
d1 = di(1,n)
d2 = di(v1,n)
d3 = di(v2,n)
# v1을 먼저 들리거나 v2를 먼저 들리거나 비교해서 더 짧은 거리를 사용한다.
result = min(d1[v2]+d2[n]+d3[v1],d1[v1]+d2[v2]+d3[n])


if result == float('inf'):
    print(-1)
else:
    print(result)