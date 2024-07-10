#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, long long int> m[2];
vector<int> v[2];

int main() {
    int n; cin >> n;

    for (int i = 0; i < 2; i++) {
        int t; cin >> t;
        int sum = 0;

        // initialize value
        v[i].push_back(0);

        // save prefix sum
        while (t--) {
            int a; cin >> a;
            sum += a;
            v[i].push_back(sum);
        }
    }

    for (int i = 0; i < 2; i++) {
        int len = v[i].size();

        // save all case of sub set
        for (int x = 0; x < len; x++) {
            for (int y = x + 1; y < len; y++) {
                int tmp = v[i][y] - v[i][x];

                // if exist
                if (m[i].find(tmp)!= m[i].end()) 
                    m[i][tmp] = m[i][tmp] + 1;
                
                else 
                    m[i].insert(make_pair(tmp, 1));
                
            }
        }
    }

    long long int ans = 0;

    // count case that can make 'T'
    for (auto p : m[1]) 
        if (m[0].find(n - p.first) != m[0].end()) ans += m[0][n - p.first] * p.second;
    
    printf("%lld\n", ans);
}