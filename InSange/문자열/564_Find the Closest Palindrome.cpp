#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    long long Convert(long long& num)
    {
        string s = to_string(num);
        int n = s.length();
        int l = (n - 1) / 2;
        int r = n / 2;
        while (l >= 0) s[r++] = s[l--];
        return stoll(s);
    }

    long long UpPal(long long num)
    {
        long long left = 0;
        long long right = num;
        long long ans = INT_MIN;

        while (left <= right)
        {
            long long mid = (right + left) / 2;
            long long palin = Convert(mid);
            if (palin < num)
            {
                ans = palin;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

    long long DownPal(long long num)
    {
        long long left = num;
        long long right = 1e18;
        long long ans = INT_MIN;

        while (left <= right) {
            long long mid = (right + left) / 2;
            long long palin = Convert(mid);
            if (palin > num)
            {
                ans = palin;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }

    string nearestPalindromic(string n) {
        long long num = stoll(n);
        long long a = UpPal(num);
        long long b = DownPal(num);

        if (abs(a - num) <= abs(b - num)) return to_string(a);

        return to_string(b);
    }
};