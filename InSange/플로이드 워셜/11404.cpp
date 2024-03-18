#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;
int n, m, a, b, c;
vector<vector<int>> cities;

void Solve()
{
	cin >> n >> m;
	n++;
	cities.assign(n, vector<int>(n, INF));
	// cities[i][i] -> (0, 0), (1, 1) ... (n, n) 부분들은 다 0으로 초기화
	// 자기 자신에서 자기 자신으로 방문 비용은 0
	for (int i = 1; i < n; i++)
	{
		cities[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (cities[a][b] < c) continue;
		cities[a][b] = c;
	}
	// 3중 for문은 밖에 있는 층은 고정된 값으로 변화를 찾는다.
	// 즉 i, j가 k에 있는 값들을 모두 방문할 때 까지 fix된다.
	// 만약 k가 두번째 혹은 첫번째(안쪽)에 있는 for문에서 돌게되면
	// i, j 가 위치한 값은 k가 배열 안의 모든 경우의 수를 돌아보기 때문에
	// 만약 돌아보는 곳에 하나라도 INF값이 있게되면 작은 값으로 최신화가 안된다.
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				cities[i][j] = min(cities[i][k] + cities[k][j], cities[i][j]);
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			cout << (cities[i][j] == INF ? 0 : cities[i][j]) << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}