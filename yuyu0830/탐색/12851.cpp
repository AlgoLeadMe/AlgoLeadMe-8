// BFS 골드 4 숨바꼭질 2 https://www.acmicpc.net/problem/12851
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int n, k;
int dist[100001] = {0, };
bool visited[100001] = {0, };

void solve() {
    priority_queue<int, vector<int>, greater<int>> q[2];
    vector<int> visitedVec;

    bool e = false;

    q[e].push(n);
    dist[n] = 1;
    visited[n] = 1;

    int time = 1, cnt = 0;

    if (n == k) {
        printf("0\n1");
        return;
    }

    while (true) {
        while (!q[e].empty()) {
            int cur = q[e].top();

            q[e].pop();

            for (int i : {cur - 1, cur * 2, cur + 1}) {
                if (i < 0 || i > 100000) continue;

                if (i == k) cnt += dist[cur] + 1;

                if (!dist[i]) {
                    q[!e].push(i);
                    visitedVec.push_back(i);
                }
                    
                if (!visited[i]) 
                    dist[i] += dist[cur];

                if (cur > k) break;
            }

            if (cur > k) {
                q[e] = priority_queue <int, vector<int>, greater<int>> ();
                break;
            }
        }

        if (cnt) {
            printf("%d\n%d", time, dist[k]);
            break;
        }
        
        while (!visitedVec.empty()) {
            int v = visitedVec.back();
            visitedVec.pop_back();

            visited[v] = 1;
        }

        e = !e;
        time++;
    }
}

int main() {
    cin >> n >> k;
    solve();

    // for (int i = 0; i < 20; i++) {
    //     printf("%d : %d\n", i, dist[i]);
    // }
}