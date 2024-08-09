#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int zeroCnt = minSwapsHelper(nums, 0);
        int oneCnt = minSwapsHelper(nums, 1);

        return min(zeroCnt, oneCnt);
    }

    int minSwapsHelper(vector<int>& data, int val) {
        int numSize = data.size();
        int totalCnt = 0;

        for (int num : data)
        {
            if (num == val) totalCnt++;
        }

        if (totalCnt == 0 || totalCnt == numSize) return 0;

        int start = 0, end = 0;
        int maxValCnt = 0, curValCnt = 0;

        while (end < totalCnt) {
            if (data[end++] == val) curValCnt++;
        }
        maxValCnt = max(maxValCnt, curValCnt);

        while (end < numSize)
        {
            if (data[start++] == val) curValCnt--;
            if (data[end++] == val) curValCnt++;
            maxValCnt = max(maxValCnt, curValCnt);
        }

        return totalCnt - maxValCnt;
    }
};