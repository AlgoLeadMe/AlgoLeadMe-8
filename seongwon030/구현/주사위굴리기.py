import sys
input = sys.stdin.readline

n,m,x,y,k = map(int,input().split())
arr = []
for _ in range(n):
  arr.append(list(map(int,input().split())))

move = list(map(int,input().split()))

# 주사위 (서,북,윗면,오,남,아랫면) 초기값
dice = [0]*6
# k=1, 동쪽으로 이동
# k=2, 서쪽으로 이동
# k=3, 북쪽으로 이동
# k=4, 남쪽으로 이동

for i in move:
  if i == 1: # 동 
    if y+1 < m:
      y+=1
      dice[0],dice[2],dice[3],dice[5] =  dice[5],dice[0],dice[2],dice[3]
      print(dice[2])
      if arr[x][y] == 0:
        arr[x][y] = dice[5]
      else:
        dice[5] = arr[x][y]
        arr[x][y] = 0
  elif i == 2: # 서
    if y-1 >=0:
      y-=1
      dice[0],dice[2],dice[3],dice[5] = dice[2],dice[3],dice[5],dice[0]
      print(dice[2])
      if arr[x][y] == 0:
        arr[x][y] = dice[5]
      else:
        dice[5] = arr[x][y]
        arr[x][y] = 0
  elif i == 3: # 북
    if x-1 >=0:
      x-=1
      dice[1],dice[2],dice[4],dice[5] = dice[2],dice[4],dice[5],dice[1]
      print(dice[2])
      if arr[x][y] == 0:
        arr[x][y] = dice[5]
      else:
        dice[5] = arr[x][y]
        arr[x][y] = 0
  elif i == 4: # 남
    if x+1 < n:
      x+=1
      dice[1],dice[2],dice[4],dice[5] = dice[5],dice[1],dice[2],dice[4]
      print(dice[2])
      if arr[x][y] == 0:
        arr[x][y] = dice[5]
      else:
        dice[5] = arr[x][y]
        arr[x][y] = 0