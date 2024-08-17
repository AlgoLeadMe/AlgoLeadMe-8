import sys
input = sys.stdin.readline

def bfs(original, x, y):
    ans = 1
    q = set([(x, y, k[y][x])])  
    while q:
        x, y, alpha = q.pop()  
        ans = max(ans, len(alpha))
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < c and 0 <= ny < r and k[ny][nx] not in alpha:
                q.add((nx, ny, alpha + original[ny][nx]))  
    return ans

r, c = map(int, input().split())
k = []
for _ in range(r):
    k.append(list(input()))

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

print(bfs(k, 0, 0))