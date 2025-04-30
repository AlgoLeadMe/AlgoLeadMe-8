#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) // 갈 수 있는 길이 처음부터 없으면
        {
            return -1;
        }

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> val;
        val.assign(row, vector<int>(col, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int dy[4] = { 0, 0, -1, 1 };
        int dx[4] = { 1, -1, 0, 0 };

        pq.push({ 0, 0, 0 });
        val[0][0] = 0;

        while (!pq.empty())
        {
            int curY = pq.top()[1];
            int curX = pq.top()[2];
            int curTime = pq.top()[0];
            pq.pop();

            if (curY == row - 1 && curX == col - 1)
            {
                return curTime;
            }

            for (int i = 0; i < 4; i++)
            {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];

                if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) continue; // Out of Bounds
                int nextTime = max(curTime + 1, grid[nextY][nextX] + ((grid[nextY][nextX] - curTime) % 2 == 0 ? 1 : 0));

                if (val[nextY][nextX] > nextTime)
                {
                    pq.push({ nextTime, nextY, nextX });
                    val[nextY][nextX] = nextTime;
                }
            }
        }

        return -1;
    }
};