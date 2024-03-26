#include <iostream>

using namespace std;

#define POW(a) a * a

int n = 0;

int crit[5][5], arr[5][5], tmp[5][5];

int calc(int x, int y, bool e) {
    // x, y 포지션의 행렬 곱 결과 연산 함수
    int v = 0;
    for (int i = 0; i < n; i++) {
        // e 여부에 따라 Doubling을 할지, Adding를 할지 결정
        v += arr[x][i] * (e ? arr[i][y] : crit[i][y]);
        v %= 1000;
    }

    return v;
}

void DoublingAdding(bool e) {
    // 행렬의 각 위치별로 곱연산 시행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = calc(i, j, e);
        }
    }

    // tmp 배열 복사
    copy(&tmp[0][0], &tmp[0][0] + 25, &arr[0][0]);
}

int main() {
    long long int b = 0;
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            crit[i][j] = arr[i][j];
        }
    }

    bool e[200];
    int cnt = 0;

    // 제곱할 수 b 분해
    while (b != 1) {
        if (b % 2 == 0) {
            b /= 2;
            e[cnt] = 1;
        }
        else {
            b -= 1;
            e[cnt] = 0;
        }
        cnt++;
    }

    for (int i = cnt - 1; i >= 0; i--) {
        // 분해한 b를 토대로 Doubling 혹은 Adding 실행
        DoublingAdding(e[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j] % 1000);
        }
        printf("\n");
    }
}