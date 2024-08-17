#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans;
        int rsize = rowSum.size();
        int csize = colSum.size();
        int rindex = 0;
        int cindex = 0;

        ans.assign(rsize, vector<int>(csize, 0));

        while (rindex < rsize || cindex < csize)
        {
            if (rindex >= rsize)
            {
                ans[rindex - 1][cindex] = colSum[cindex];
                cindex++;
                continue;
            }
            else if (cindex >= csize)
            {
                ans[rindex][cindex - 1] = rowSum[rindex];
                rindex++;
                continue;
            }

            int val = min(colSum[cindex], rowSum[rindex]);

            ans[rindex][cindex] = val;
            rowSum[rindex] -= val;
            colSum[cindex] -= val;

            if (!rowSum[rindex])
            {
                rindex++;
            }
            if (!colSum[cindex])
            {
                cindex++;
            }
        }

        return ans;
    }
};