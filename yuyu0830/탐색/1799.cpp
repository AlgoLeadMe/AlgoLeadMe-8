#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int leftArr[2][11] = {0, };
int rightArr[2][11] = {0, };
int map[11][11] = {0, };

int n, ans[2] = {0, }, m[2] = {0, };
vector<ii> v[2];

void solve(int color, int idx) {
    // current color, idx bishop's position
    int x = v[color][idx].first;
    int y = v[color][idx].second;

    // position about each diagonal direction
    int rightPos = (x + y) / 2;
    int leftPos = ((n - x - 1) + y) / 2;

    // if can set bishop in (x, y) position
    if (map[x][y] && !rightArr[color][rightPos] && !leftArr[color][leftPos]) {
        // then check diagonal position
        rightArr[color][rightPos] = 1;
        leftArr[color][leftPos] = 1;

        // update max value
        m[color] = max(m[color], ++ans[color]);

        // search same color, another position bishop
        for (int i = idx + 1; i < v[color].size(); i++) 
            solve(color, i);
        
        // set off current bishop
        rightArr[color][rightPos] = 0;
        leftArr[color][leftPos] = 0;

        ans[color]--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            map[i][j] = t;
            // if bishop can set in (i, j) push in vector[board color]
            if (t) v[i % 2 != j % 2].push_back(make_pair(i, j));
        }
    }

    for (int color = 0; color < 2; color++) {
        for (int i = 0; i < v[color].size(); i++) {
            // search every position that can set in bishop
            solve(color, i);

            // if (left bishop + current max value) less then max value then break this search
            if (ans[color] + (v[color].size() - i - 1) < m[color]) break;
        }   
    }

    printf("%d\n", m[0] + m[1]);
}