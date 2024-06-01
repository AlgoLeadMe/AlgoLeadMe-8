import heapq

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

T = int(input())
for i in range(T):
  max_heap = []
  min_heap = [] 
  re = []

  n = int(input()) 
  if n%2 == 0:
    print(n//2)
  else:
    print(n//2+1)

  for j in range(n//10 + 1):
    arr = list(map(int,input().split()))
    for k in range(len(arr)):
      push_num(arr[k])
      if k%2 == 0:
        re.append(-max_heap[0])
  if n%2 == 0:
    re.append(-max_heap[0])
  
  cnt = 0
  for p in range(len(re)):
    cnt += 1
    print(re[p],end=' ')
    if cnt%10 == 0:
      print()
  print()