#include <iostream>

#define MOD 1000000000

using namespace std;

int arr[101][10][1024] = {0, };

int main() {
    int n; cin >> n;

    for (int i = 1; i < 10; i++) {
        arr[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j) {
                    arr[i][j][k | (1 << j)] += arr[i - 1][j - 1][k];
                    arr[i][j][k | (1 << j)] %= MOD;
                } 

                if (j != 9) {
                    arr[i][j][k | (1 << j)] += arr[i - 1][j + 1][k];
                    arr[i][j][k | (1 << j)] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    
    for (int i = 0; i < 10; i++) {
        ans += arr[n][i][1023];
        ans %= MOD;
    }

    printf("%d\n", ans);
}