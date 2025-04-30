#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll arr[5001] = {0, };
ll minValue = 999999999999;
ll ans[3] = {0, };

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        ll start = i + 1;
        ll end = n;

        while (start < end) {
            ll cur = arr[i] + arr[start] + arr[end];

            if (abs(cur) < minValue) {
                minValue = abs(cur);

                ans[0] = arr[i];
                ans[1] = arr[start];
                ans[2] = arr[end];
            }

            if (cur < 0) start++;
            else end--;
        }
    }

    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}