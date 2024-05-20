import sys

input = sys.stdin.readline
dp = [1,2,4,7]
p = 4
for i in range(int(input())):
  n = int(input())
  while(n>p):
    dp.append((dp[p-3]+dp[p-2]+dp[p-1])%1000000009)
    p+=1
  print(dp[n-1])