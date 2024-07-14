#include <iostream>
#include <queue>
#include <math.h>

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

using namespace std;

struct point {
    float x, y;
    point(float X, float Y) : x(X), y(Y) {};
    point() {};
};

point arr[10000];

struct edge {
    int vertex1, vertex2;
    float value;
    edge(int v1, int v2) : vertex1(v1), vertex2(v2) {
        value = sqrt(pow(arr[v1].x - arr[v2].x, 2) + pow(arr[v1].y - arr[v2].y, 2));
    }
};

struct cmp {
    bool operator()(edge a, edge b) { return a.value > b.value; }
};

int parent[101] = {0, };

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int x, int y) { parent[find(x)] = find(y); }

bool isUnion(int x, int y) { return find(x) == find(y); }

int main() {
    fastio
    int n; cin >> n;

    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    priority_queue<edge, vector<edge>, cmp> q;

    // 별 위치 저장
    for (int i = 0; i < n; i++) {
        float a, b; cin >> a >> b;
        arr[i] = point(a, b);
    }

    // 각 별마다 이을 수 있는 모든 선 우선 순위 큐에 저장
    // 우선 순위 큐는 선분의 길이를 기준으로 정렬
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            q.push(edge(i, j));
        
    int cnt = 1;
    float ans = 0.f;

    while (cnt != n) {
        edge tmp = q.top();
        q.pop();

        int v1 = tmp.vertex1;
        int v2 = tmp.vertex2;

        if (isUnion(v1, v2)) continue;

        merge(v1, v2);
        cnt++;
        ans += tmp.value;

        if (cnt == n) {
            printf("%.2f\n", ans);
            return 0;
        }
    }

}