#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define NUM 10002

using namespace std;

// x : 이 노드를 선택하지 않았을 때의 최대값
// y : 이 노드를 선택했을 때의 최대값
struct node {
    int x, y;
    node(int X, int Y) : x(X), y(Y) {};
    int m() { return max(x, y); }
};

bool visited[NUM] = {0, };
int arr[NUM] = {0, };
vector<int> v[NUM];

node f(int t) {
    visited[t] = true;
    
    node tmp(0, arr[t]);

    // 이 노드에서 갈 수 있는 가지들을 탐색
    for (auto i : v[t]) {
        // 방문한 노드면 가지 않는다
        if (!visited[i]) {
            node a = f(i);

            tmp.x += a.m();
            tmp.y += a.x;
        }
    }

    return tmp;
}

int main() {
    fastio
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    printf("%d\n", f(1).m());
}