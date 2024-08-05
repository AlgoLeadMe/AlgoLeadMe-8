import sys
input = sys.stdin.readline

def find(x):
  if x!=root[x]:
    root[x] = find(root[x])
  return root[x]


while True:
  V,E = map(int,input().split())
  if V==0 and E==0:
    break
  root = [i for i in range(V+1)]
  edge = [] # 간선리스트
  for i in range(E):
    a,b,c = map(int,input().split())
    edge.append((a,b,c))

  # 비용을 기준으로 오름차순
  edge.sort(key=lambda x:x[2])

  ans = 0
  for a,b,c in edge:
    aRoot = find(a)
    bRoot = find(b)
    if aRoot != bRoot:
      if aRoot < bRoot:
        root[bRoot] = aRoot
      else:
        root[aRoot] = bRoot
    else:
      ans+=c 

  print(ans)