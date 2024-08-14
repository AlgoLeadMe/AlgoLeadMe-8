#include <iostream>
#include <vector>
#include <queue>

#define NUM 32001

using namespace std;

int n, m;
int enter[NUM] = {0, };
bool visited[NUM] = {0, };

vector<int> rule[NUM];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        rule[a].push_back(b);
        enter[b]++;
    }

    queue<int> empty;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!enter[i]) {
            empty.push(i);
            visited[i] = true;
        }
    }

    while (!empty.empty()) {
        int cur = empty.front();
        empty.pop();

        ans.push_back(cur);

        for (int i : rule[cur]) {
            enter[i]--;

            if (!enter[i]) {
                empty.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i : ans) {
        printf("%d ", i);
    }
} 