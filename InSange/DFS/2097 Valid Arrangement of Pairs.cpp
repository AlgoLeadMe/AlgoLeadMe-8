#include <unordered_map>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, deque<int>> nodes;
    unordered_map<int, int> inDegree;
    unordered_map<int, int> outDegree;

    vector<int> result;

    void DFS(int index)
    {
        while (!nodes[index].empty())
        {
            int nextNode = nodes[index].front();
            nodes[index].pop_front();
            DFS(nextNode);
        }
        result.push_back(index); // 결국. 모든 노드들을 방문했다면. 즉 비워져있는 노드에 방문했다면 도착지 경로가 거꾸로 이어지게 됨.
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (const vector<int>& pair : pairs)
        {
            int depart = pair[0];
            int dest = pair[1];

            nodes[depart].push_back(dest);
            inDegree[dest]++;
            outDegree[depart]++;
        }

        int startNode = -1;

        for (const auto& degree : outDegree)
        {
            int curNode = degree.first;
            if (outDegree[curNode] == inDegree[curNode] + 1) // 현재 노드에서 출발지가 현재 노드로 들어오는 진입의 개수 + 1일 경우. 이 노드는 돌고 돌아 다시 해당 노드를 거쳐야 모든 노드를 방문할 수 있음.
            {
                startNode = curNode;
                break;
            }
        }

        if (startNode == -1) // 출발 노드를 발견 못했다면 모든 노드는 각각 하나의 진입, 진출지를 동일하게 가지는 것
        {
            startNode = pairs[0][0];
        }

        DFS(startNode);

        vector<vector<int>> ans;
        for (int i = result.size() - 1; i > 0; i--)
        {
            ans.push_back({ result[i], result[i - 1] }); // 출발지와 도착지를 거꾸로 변경
        }

        return ans;
    }
};