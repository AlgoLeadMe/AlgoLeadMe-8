#include <iostream>
#include <queue>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int f() {
    int n, m, t;
    cin >> n >> m;

    deque<bool> visited(n + 1, 0);
    vector<int> arr(n + 1, 0), enter(n + 1, 0), rule[n + 1];

    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        rule[a].push_back(b);
        enter[b]++;
    }

    cin >> t;
    
    int ret = 0;

    vector<int> tmp[2];
    bool e = false;

    while (true) {
        for (int i = 1; i <= n; i++) {
            if (!enter[i] && !visited[i]) {
                if (i == t) return ret + arr[i];

                visited[i] = true;
                tmp[e].push_back(i);
            }
        }

        int m = 99999999;

        for (int i : tmp[e]) { m = min(m, arr[i]); }

        while (!tmp[e].empty()) {
            int a = tmp[e].back();
            tmp[e].pop_back();
            
            arr[a] -= m;
            
            if (arr[a]) { tmp[!e].push_back(a); }
            else { for (int i : rule[a]) { enter[i]--; } }
        }

        e = !e;
        ret += m;
    }
}

int main() {
    fastio

    int testCase; cin >> testCase;
    while (testCase--) 
        printf("%d\n", f());
}