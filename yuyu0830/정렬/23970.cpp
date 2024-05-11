#include <iostream>

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

using namespace std;

int arr[2][10001] = {0, };
int n, arrPtr = 0;

bool same() {
    // start at 'arrPtr'
    for (int i = arrPtr; i < n; i++) {
        // if diff, terminate this function
        if (arr[0][i] != arr[1][i]) return false;
        // if same, then that index will same forever. no reason to compare again.
        arrPtr++;
    }
    return true;
}

int main() {
    fastio 
    cin >> n;
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
        
    int rnd = n - 1, ptr = 0;

    // it can be same before sort
    if (same()) {
        printf("1\n");
        return 0;
    }

    while (rnd) {
        // sort [0] to [ptr - rnd]
        int a = arr[0][ptr];
        int b = arr[0][ptr + 1];

        arr[0][ptr] = min(a, b);
        arr[0][ptr + 1] = max(a, b);

        // if this index is last index in this round
        if (++ptr == rnd) {
            // next round
            ptr = 0;
            rnd--;
        }

        if (same()) {
            // if arr is same
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
}