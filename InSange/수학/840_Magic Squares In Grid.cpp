#include <vector>

using namespace std;

class Solution {
public:
    bool Check(int r, int c, vector<vector<int>>& grid)
    {
        vector<bool> isCheck(10, false);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9) return false;
                if (isCheck[num]) return false;
                isCheck[num] = true;
            }
        }

        int standard_num = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        if (standard_num != grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c]) return false;

        for (int i = 0; i < 3; i++)
        {
            if (standard_num != (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2])) return false;
        }

        for (int i = 0; i < 3; i++)
        {
            if (standard_num != (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i])) return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int col = grid[0].size(), row = grid.size();

        if (col < 3 || row < 3) return 0;

        int ans = 0;

        for (int i = 0; i < row - 2; i++)
        {
            for (int j = 0; j < col - 2; j++)
            {
                if (Check(i, j, grid)) ans++;
            }
        }

        return ans;
    }
};