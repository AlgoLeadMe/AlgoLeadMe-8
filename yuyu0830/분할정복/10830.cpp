#include <iostream>

using namespace std;

int n = 0;
long long int b = 0;

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
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            tmp[i][j] = calc(i, j, e);

    // tmp 배열 복사
    copy(&tmp[0][0], &tmp[0][0] + 25, &arr[0][0]);
}

int main() {
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            crit[i][j] = arr[i][j];
        }
    }

    long long int pointer = 137438953472; // 2^38

    // b와 비교할 수 있는 위치로 포인터 세팅
    while (!(b & pointer)) pointer = pointer >> 1; 
    pointer = pointer >> 1;

    // 앞에서부터 bit 연산으로 1인지 0인지 판단
    while (pointer) {
        DoublingAdding(1);

        if (b & pointer) // 1이면 Adding 연산 추가 수행
            DoublingAdding(0);
            
        pointer = pointer >> 1; // bit Shift
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j] % 1000);
        }
        printf("\n");
    }
}