#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b, answer;
vector<pair<int, int>> line;
vector<int> dp;

void Solve()
{
	cin >> N;

	answer = 0;
	dp.assign(N + 1, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		line.push_back({ a, b });
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//cout << line[i].first << ", " << line[j].first << "일 때\n";
			if (line[j].second < line[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
				//cout << line[i].first << "-> i 의 dp 값 : " << dp[i] << "\n";
				//cout << line[j].first << "-> j 의 dp 값 : " << dp[j] << "\n";
			}
		}

		answer = max(answer, dp[i]);
	}

	cout << N - answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}