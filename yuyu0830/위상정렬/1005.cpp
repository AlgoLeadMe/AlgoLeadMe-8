#include <iostream>
#include <queue>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int f() {
    int n, m, t;
    cin >> n >> m;

    deque<bool> visited(n + 1, 0);
    vector<int> arr(n + 1, 0), enter(n + 1, 0), rule[n + 1];

    // 건물 짓는 속도
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    
    // 건물 순서
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        rule[a].push_back(b);
        enter[b]++;
    }

    cin >> t;
    
    int ret = 0;

    vector<int> tmp[2];
    bool e = false;

    // 원하는 건물 지을 수 있을 때까지 반복
    while (true) {
        // ret 시간에 지을 수 있는 건물들 탐색 및 tmp 큐에 push
        // 원하는 건물을 지을 수 있으면 함수 종료 및 값 반환
        for (int i = 1; i <= n; i++) {
            if (!enter[i] && !visited[i]) {
                if (i == t) return ret + arr[i];

                visited[i] = true;
                tmp[e].push_back(i);
            }
        }

        int m = 99999999;

        // 지금 짓고있는 건물 + 지을 수 있는 건물 중 시간 가장 적게 남은 값 탐색
        for (int i : tmp[e]) { m = min(m, arr[i]); }

        // tmp 큐에 있는 모든 건물들 m만큼 건설 진행, 완성되면 큐에서 제거
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