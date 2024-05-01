#include <iostream>

using namespace std;

string s, boom;
int blen;

void Solve()
{
	cin >> s >> boom;

	blen = boom.length();
	
	string st = "";
	for (char c : s)
	{
		st.push_back(c);

		if (c == boom[blen-1] && st.size() >= blen)
		{
			bool flag = true;

			for (int i = 0; i < blen; i++)
			{
				if (boom[i] != st[st.length() - blen + i])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				for (int i = 0; i < blen; i++)
				{
					st.pop_back();
				}
			}
		}
	}

	if (st == "") cout << "FRULA";
	else cout << st;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}