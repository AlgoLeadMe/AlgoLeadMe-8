#include <iostream>
#include <queue>

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

using namespace std;

struct edge {
    int vertex1, vertex2, value;

    edge(int v1, int v2, int _value) : vertex1(v1), vertex2(v2), value(_value) {};
};

struct cmp {
    bool operator()(edge a, edge b) { return a.value > b.value; }
};

int parent[1001] = {0, };
bool manOnly[1001] = {0, };

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int x, int y) { parent[find(x)] = find(y); }

bool isUnion(int x, int y) { return find(x) == find(y); }

int main() {
    fastio
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        // Union Initialize
        parent[i] = i;

        // is University Man only?
        char c; cin >> c;
        if (c == 'M') manOnly[i] = 1;
    }

    priority_queue<edge, vector<edge>, cmp> q;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        // No same gender...
        if (manOnly[a] == manOnly[b]) continue;

        q.push(edge(a, b, c));
    }

    int cnt = 1, ans = 0;
    
    while (!q.empty()) {
        edge tmp = q.top();
        q.pop();

        int v1 = tmp.vertex1;
        int v2 = tmp.vertex2;

        if (isUnion(v1, v2)) continue;

        merge(v1, v2);
        cnt++;
        ans += tmp.value;

        if (cnt == n) {
            printf("%d\n", ans);
            return 0;
        }
    }

    printf("-1\n");
}