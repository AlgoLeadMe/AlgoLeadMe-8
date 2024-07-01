#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= numRows) return s;

        vector<string>v(numRows, "");

        int i, j, dir;
        j = 0;
        dir = -1;

        for (i = 0; i < s.size(); i++)
        {
            if (j == numRows - 1 || j == 0) dir *= -1;
            v[j] += s[i];
            if (dir == 1) j++;
            else j--;
        }

        string answer;
        answer = "";

        for (auto c : v)
        {
            answer += c;
        }

        return answer;
    }
};