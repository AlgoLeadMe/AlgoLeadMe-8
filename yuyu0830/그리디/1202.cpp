#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

ii gems[300001];
int bags[300001] = {0, };

priority_queue<int> q;

int main() {
    fastio

    // input
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) 
        cin >> gems[i].first >> gems[i].second;
    
    for (int i = 0; i < k; i++) 
        cin >> bags[i];
    
    // Sort gems, bags ascending order
    // gems sort by weight
    sort(gems, gems + n);
    sort(bags, bags + k);

    // ans can be more then int max value
    // 300,000 * 1,000,000
    long long int ans = 0;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        int curBag = bags[i];

        // push all the gems that can put in current bag into the priority queue 
        while (cnt < n && gems[cnt].first <= curBag) {
            q.push(gems[cnt].second);
            cnt++;
        }

        // if queue is not empty, top of queue will be max price that can get in current bag
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    printf("%lld\n", ans);
}