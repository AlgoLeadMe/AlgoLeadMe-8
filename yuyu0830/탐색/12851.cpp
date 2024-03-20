// BFS 골드 4 숨바꼭질 2 https://www.acmicpc.net/problem/12851
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int dist[100001] = {0, };
bool visited[100001] = {0, };

void solve() {
    // 2개의 큐를 번갈아 사용하기 위한 큐 배열, 불리언 변수
    priority_queue<int, vector<int>, greater<int>> q[2];
    bool e = false;

    // 현재 탐색에서 탐색중인 위치를 저장
    vector<int> visitedVec;

    q[e].push(n);
    dist[n] = 1;
    visited[n] = 1;

    if (n == k) {
        printf("0\n1");
        return;
    }

    int time = 1, cnt = 0;

    while (true) {
        while (!q[e].empty()) {
            int cur = q[e].top();

            q[e].pop();

            for (int i : {cur - 1, cur * 2, cur + 1}) {
                if (i < 0 || i > 100000) continue;

                // 목표 위치에 도착한 경우 경우의 수 저장
                if (i == k) cnt += dist[cur] + 1;

                // 첫 방문인 경우 다음 탐색 큐에 저장
                if (!dist[i]) {
                    q[!e].push(i);
                    visitedVec.push_back(i);
                }
                    
                // 방문한 위치에 현재 위치의 경우의 수 더하기
                // 이전 탐색에서 탐색한 위치는 방문 안하도록
                if (!visited[i]) 
                    dist[i] += dist[cur];

                // 탐색 도중 숫자가 커지면 탐색을 종료, 탐색중 큐 비우기
                if (cur > k) break;
            }

            // 숫자가 커져서 탐색을 종료하면 남은 큐는 비워주기
            if (cur > k) {
                q[e] = priority_queue <int, vector<int>, greater<int>> ();
                break;
            }
        }

        if (cnt) {
            printf("%d\n%d", time, dist[k]);
            break;
        }
        
        // 이번 탐색에서 방문한 노드들 전부 표시 해주기
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
}