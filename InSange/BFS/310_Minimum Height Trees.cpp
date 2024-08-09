#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> m;
        vector<int> ans;
        vector<bool> check(n, false);
        int* degree = new int[n] {0};

        for (vector<int> node : edges)
        {
            m[node[0]].push_back(node[1]);
            m[node[1]].push_back(node[0]);
            degree[node[0]]++;
            degree[node[1]]++;
        }
        int current_n = n;

        queue<int> q;
        if (current_n > 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (degree[i] == 1 && check[i] == false)
                {
                    check[i] = true;
                    q.push(i);
                    current_n--;
                }
            }
        }
        while (current_n > 2 && !q.empty())
        {
            int size = q.size();

            for (int j = 0; j < size; j++)
            {
                int remove_n = q.front();
                q.pop();

                for (auto node : m[remove_n])
                {
                    degree[node]--;
                    if (degree[node] == 1)
                    {
                        q.push(node);
                        check[node] = true;
                        current_n--;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (check[i] == false) ans.push_back(i);
        }

        return ans;
    }
};