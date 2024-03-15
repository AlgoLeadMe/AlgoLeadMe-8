// 최단 경로 골드 3 웜홀 https://www.acmicpc.net/problem/1865
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define MAX 9999999
#define SIZE 502
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct edge {
    int s, e, v;
};

bool f() {
    int n, road, wormhole; cin >> n >> road >> wormhole;

    int s, e, v;
    vector<edge> edges;

    // input
    while (road--) {
        cin >> s >> e >> v; // start, end, value
        edges.push_back({s, e, v});
        edges.push_back({e, s, v});
    }

    while (wormhole--) {
        cin >> s >> e >> v;
        edges.push_back({s, e, -v});
    }

    // Search all nodes n time
    vector<int> dist(n + 1, MAX);
    dist[1] = 0;

    for (int node = 1; node <= n; node++) {
        for (auto next : edges) {
            s = next.s;
            e = next.e;
            v = next.v;

            if (dist[e] > dist[s] + v) 
                dist[e] = dist[s] + v;
        }
    }

    // Search one more time
    for (auto next : edges) {
        s = next.s;
        e = next.e;
        v = next.v;

        if (dist[e] > dist[s] + v) 
            return true;
    }

    return false;
}

int main() {
    fastio;
    int testCase; cin >> testCase;
    while (testCase--) {
        if (f()) printf("YES\n");
        else printf("NO\n");
    }
}