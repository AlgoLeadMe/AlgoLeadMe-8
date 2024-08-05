#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        string ans;
        string word;

        ans = "";

        for (char c : s)
        {
            if (c == ')')
            {
                word = "";
                while (!st.empty() && st.top() != '(') {
                    word += st.top();
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
                for (char w : word)
                {
                    st.push(w);
                }
            }
            else
            {
                st.push(c);
            }
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }


        return ans;
    }
};
