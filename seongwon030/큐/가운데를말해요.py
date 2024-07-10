import heapq
import sys

input = sys.stdin.readline

max_heap = []
min_heap = []
def push_num(num):
  # max_heap과 min_heap 크기 같으면 max_heap에 넣음
  if len(max_heap) == len(min_heap):
    heapq.heappush(max_heap, -num)
  else:
    # 크기가 다르면 이전에 max_heap에 넣은 것이므로
    # min_heap에 넣는다 
    heapq.heappush(min_heap, num)

  if min_heap and -max_heap[0] > min_heap[0]:
    min = heapq.heappop(min_heap)
    max = -heapq.heappop(max_heap)
    heapq.heappush(max_heap, -min)
    heapq.heappush(min_heap, max)

n = int(input())
for i in range(n):
  push_num(int(input()))
  print(-max_heap[0])