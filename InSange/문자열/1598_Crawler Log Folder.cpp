#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int height;

        height = 0;

        for (auto str : logs)
        {
            if (str[0] != '.') height++;
            else if (str == "../") height = (height ? height - 1 : 0);
        }

        return height;
    }
};