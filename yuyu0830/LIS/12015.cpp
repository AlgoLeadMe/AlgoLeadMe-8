#include <iostream>

#define NUM 1000001
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n, cnt = 1;
int arr[NUM] = {0, };
int m[NUM] = {0, };

// Binary Search
int bs(int value) {
    int low = 0, mid, high = cnt - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (m[mid] == value)
            return -1;

        if (value < m[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return mid + (value < m[mid] ? -1 : 0);
}

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++)  
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        // if arr[i] is bigger than before
        if (arr[i] > m[cnt - 1]) {
            m[cnt++] = arr[i];
            continue;
        } 

        // if arr[i] is smaller than before 
        // find arr[i]'s position   
        int t = bs(arr[i]);
        // change m[t] to arr[i]
        m[t + 1] = arr[i] < m[t + 1] ? arr[i] : m[t + 1];
    }

    printf("%d\n", cnt - 1);
}