#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b)
        {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        vector<string> ans;

        for (auto s : words) um[s]++;
        for (pair<string, int> v : um) pq.push({ v.second, v.first });

        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};