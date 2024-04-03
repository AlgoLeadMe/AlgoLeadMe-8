// 백트래킹 골드 4 스도쿠 https://www.acmicpc.net/problem/2239
#include <iostream>

using namespace std;

int sudoku[9][9] = {0, 0};

bool solve(int pos) {
    // 마지막 칸 순회중이면 true 리턴
    if (pos == 81) return true;

    // pos 값 통해 x, y 값 추출
    int x = pos % 9;
    int y = pos / 9;

    // 현재 탐색 위치에 값이 있으면 바로 다음 탐색
    if (sudoku[y][x]) {
        if (solve(pos + 1)) return true;
        return false;
    }

    // 3x3 칸 탐색을 위한 포지션 값
    int sx = (x / 3) * 3;
    int sy = (y / 3) * 3;

    // 1~9까지 겹치는 수가 없는지 체크
    for (int i = 1; i <= 9; i++) {
        bool flag = true;

        // 가로, 세로, 3x3 칸 탐색
        for (int j = 0; j < 9; j++) {
            if (sudoku[j][x] == i || sudoku[y][j] == i || sudoku[sy + (j / 3)][sx + (j % 3)] == i) {
                // 겹치는게 있는 경우
                flag = false;
                break;
            }
        }

        // 가로, 세로, 3x3 칸 탐색이 무사히 종료된 경우
        if (flag) {
            sudoku[y][x] = i;
            if (solve(pos + 1)) return true;
            sudoku[y][x] = 0;
        }
    }

    return false;
}

int main() {
    // Input
    for (int i = 0; i < 9; i++) {
        char str[10]; cin >> str;
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = str[j] - 48;
        }
    }

    solve(0);

    // Output
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}