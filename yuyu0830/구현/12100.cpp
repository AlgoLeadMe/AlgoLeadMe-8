#include <iostream>

using namespace std;

int map[21][21] = {0, };
int n, ans = 0;
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool isin(int t) { return t >= 0 && t < n; }

bool move(int m[21][21], int d) {
    // 반환 값(e)은 움직임 여부
    bool e = false;

    // vertical : 움직임 방향이 가로인지 세로인지
    // plus : 움직임 방향이 + 방향인지 - 방향인지
    bool vertical = d < 2, plus = d % 2 == 0;

    // 한 번 더해진 부분은 다시 더해지면 안되니까 방문 처리
    bool visited[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;

    for (int i = 0; i < n; i++) {
        // 현재 탐색 위치의 x, y 좌표값
        int x = vertical ? i : (plus ? 1 : n - 2);
        int y = vertical ? (plus ? 1 : n - 2) : i;

        // 탐색 범위 안에 있는 동안만 탐색
        while (isin(vertical ? y : x)) {
            // 현재 탐색 위치에 값이 있다면 이동 해야함
            if (m[x][y]) {
                // 값 저장 및 현재 탐색 위치 0으로
                int tmp = m[x][y];
                m[x][y] = 0;

                // 어디까지 이동할지 탐색할 임시 탐색 위치의 x, y 좌표값
                int tx = x - dir[d][0];
                int ty = y - dir[d][1];

                while (true) {
                    // 임시 탐색 위치에 값이 있다면
                    if (m[tx][ty]) {
                        // 값이 있고, 현재 탐색 위치와 값이 같고, 방문한 적이 없다면
                        // 임시 탐색 위치의 값에 더해짐
                        if (tmp == m[tx][ty] && !visited[tx][ty]) {
                            e = true;
                            visited[tx][ty] = true;
                            break;
                        }
                        // 값이 다르거나, 방문한 적이 있으면
                        // 임시 탐색 위치에서 한 칸 전으로 이동
                        else {
                            tx += dir[d][0];
                            ty += dir[d][1];
                            break;
                        }
                    }

                    // 더 이동 가능한지 체크
                    if (!isin(vertical ? ty - dir[d][1]: tx - dir[d][0])) 
                        break;

                    // 움직임 여부 체크
                    e = true;

                    // 임시 탐색 위치 이동
                    tx -= dir[d][0];
                    ty -= dir[d][1];
                }

                // 임시 탐색 위치까지 이동 처리
                m[tx][ty] += tmp;
                // 최대 값 처리
                ans = max(ans, m[tx][ty]);
            }

            // 현재 탐색 위치 이동
            x += dir[d][0];
            y += dir[d][1];
        }
    }

    return e;
}

void f(int m[21][21], int depth) {
    // depth가 5가 되면 탐색 종료
    if (depth == 5) return;

    int tm[21][21];

    for (int d = 0; d < 4; d++) {
        // 임시 map 생성
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                tm[i][j] = m[i][j];
            
        // 만약 움직임이 없으면 굳이 더 탐색하지 않는다.
        if (move(tm, d)) 
            f(tm, depth + 1);
 
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            ans = max(ans, map[i][j]);
        }
    }

    f(map, 0);
    printf("%d\n", ans);
}