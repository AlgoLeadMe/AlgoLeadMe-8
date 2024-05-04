#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        q.push(t);
    }

    bool first = true;
    int max = 1;

    while (!q.empty()) {
        int t = q.top();
        q.pop();

        // when First number isn't 1
        if (first && t != 1) 
            break;

        first = false;
        
        // can search more?
        if (t <= max) max += t;
        else break;
    }

    printf("%d\n", max);
}