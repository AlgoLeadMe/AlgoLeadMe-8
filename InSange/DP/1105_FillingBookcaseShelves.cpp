#include <vector>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int arrSize = books.size();
        vector<int> heightArr(arrSize + 1, 0);

        for (int i = 1; i <= arrSize; i++)
        {
            int width = books[i - 1][0];
            int height = books[i - 1][1];

            heightArr[i] = heightArr[i - 1] + height; // check Next Floor
            for (int j = i - 1; j > 0; j--)
            {
                if (width + books[j - 1][0] > shelfWidth) break;
                width += books[j - 1][0]; // check the same Floor
                height = max(height, books[j - 1][1]);    // same Floor height compare with before book height
                heightArr[i] = min(heightArr[i], heightArr[j - 1] + height);  // where make min
            }
        }

        return heightArr[arrSize];
    }
};