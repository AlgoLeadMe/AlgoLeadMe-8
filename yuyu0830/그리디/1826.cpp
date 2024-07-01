#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

struct cmp{
    bool operator() (ii &a, ii &b) {
        if (a.first > b.first) return true;
        return false;
    }
};

struct cmpB{
    bool operator() (ii &a, ii &b) {
        if (a.second < b.second) return true;
        return false;
    }
};

int main() {
    priority_queue<ii, vector<ii>, cmp> q;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        q.push(make_pair(a, b));
    }

    int dest, fuel; cin >> dest >> fuel;
    int cur = 0, ans = 0;
    
    priority_queue<ii, vector<ii>, cmpB> reachable;

    while (cur <= dest) {
        while (!q.empty()) {
            if (q.top().first <= cur + fuel) {
                reachable.push(q.top());
                q.pop();
            }
            else break;
        }

        while (true) {
            if (cur + fuel >= dest) {
                printf("%d\n", ans);
                return 0;
            }

            if (reachable.empty()) {
                printf("-1\n");
                return 0;
            }

            int f = reachable.top().first;
            int s = reachable.top().second;

            if (f > cur) fuel -= f - cur;
            fuel += s;
    
            cur = f > cur ? f : cur;
            ans++;

            reachable.pop();

            if (q.top().first <= cur + fuel) break;
        }
    }

    printf("%d\n", ans);
}
