#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> conn;   // road
        priority_queue<pair<long long, int>> pq;  // connect degree first: degree, second: index
        long long answer = 0;

        conn.assign(n, vector<int>());

        for (auto road : roads)
        {
            int v1 = road[0];
            int v2 = road[1];

            conn[v1].push_back(v2);
            conn[v2].push_back(v1);
        }

        for (int i = 0; i < n; i++)
        {
            pq.push({ conn[i].size(), i });
        }

        while (!pq.empty())
        {
            pair<long long, int> cur;
            cur = pq.top();
            pq.pop();

            answer += (n-- * cur.first);
        }

        return answer;
    }
};