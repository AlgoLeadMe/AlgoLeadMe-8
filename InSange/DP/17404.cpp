#include <iostream>
#include <vector>

using namespace std;

int const MAX_INT = 999999999;
int N, answer;
vector<vector<int>> houses;
vector<vector<int>> dp;

void Solve()
{
	cin >> N;
	houses.assign(N + 1, vector<int>(3, 0));
	dp.assign(N + 1, vector<int>(3, 0));
	answer = MAX_INT;

	for (int i = 1; i <= N; i++)
	{
		cin >> houses[i][0] >> houses[i][1] >> houses[i][2];
	}

	for (int rgb = 0; rgb < 3; rgb++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == rgb) dp[1][i] = houses[1][i];
			else dp[1][i] = MAX_INT;
		}

		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == rgb) continue;
			else answer = min(answer, dp[N][i]);
		}
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