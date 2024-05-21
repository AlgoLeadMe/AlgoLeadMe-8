#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long N, n, a, b, answer;
vector<int> line;
stack<pair<int, int>> st;

// a1 보다 b가 크면 종료
// a1 보다 b가 작다면 다음 b는 
void Solve()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		line.push_back(n);
	}

	for (auto num : line)
	{
		int cnt = 1;

		while (!st.empty())
		{
			int cur = st.top().first;
			int cur_cnt = st.top().second;
			if (cur < num)
			{
				answer+= cur_cnt;
			}
			else if (cur == num)
			{
				answer += cur_cnt;
				cnt += cur_cnt;
			}
			else //if(st.top().first > num)
			{
				answer++;
				break;
			}
			st.pop();
		}
		//cout << num << ", " << answer << "\n";
		st.push({num, cnt});
	}

	cout << answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}