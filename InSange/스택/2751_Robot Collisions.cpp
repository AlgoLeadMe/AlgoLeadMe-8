#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> IndexArr;
        stack<pair<int, int>> Rst;

        for (int i = 0; i < positions.size(); i++)
        {
            IndexArr.push({ positions[i], i });
        }

        while (!IndexArr.empty())
        {
            int val = IndexArr.top().first;
            int index = IndexArr.top().second;

            cout << val << ", " << index << "\n";
            IndexArr.pop();

            if (directions[index] == 'L')
            {
                while (!Rst.empty())
                {
                    int stVal = Rst.top().first;
                    int stIndex = Rst.top().second;

                    if (healths[stIndex] == healths[index])
                    {
                        healths[stIndex] = 0;
                        healths[index] = 0;
                        Rst.pop();
                        break;
                    }
                    else if (healths[stIndex] > healths[index])
                    {
                        healths[index] = 0;
                        healths[stIndex]--;
                        break;
                    }
                    else
                    {
                        healths[stIndex] = 0;
                        healths[index]--;
                        Rst.pop();
                    }
                }
            }
            else
            {
                Rst.push({ val, index });
            }
        }

        for (int health : healths)
        {
            if (health) ans.push_back(health);
        }

        return ans;
    }
};