#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> record;
int t;
bool draw_flag, flag;
vector<pair<int, int>> game = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
													 {1, 2}, {1, 3}, {1, 4}, {1, 5},
													 {2, 3}, {2, 4}, {2, 5},
													 {3, 4}, {3, 5},
													 {4, 5} };

bool CheckPlay(int round)
{
	if (round == 15)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (record[i][j]) return false;
			}
		}
		return true;
	}

	int firstTeam, secondTeam;
	firstTeam = game[round].first;
	secondTeam = game[round].second;

	if (record[firstTeam][0] && record[secondTeam][2])	// first team win, second team lose
	{
		--record[firstTeam][0];
		--record[secondTeam][2];
		if (CheckPlay(round + 1)) return true;
		++record[firstTeam][0];
		++record[secondTeam][2];
	}

	if (record[firstTeam][1] && record[secondTeam][1])	// first team draw, second team draw
	{
		--record[firstTeam][1];
		--record[secondTeam][1];
		if (CheckPlay(round + 1)) return true;
		++record[firstTeam][1];
		++record[secondTeam][1];
	}

	if (record[firstTeam][2] && record[secondTeam][0])	// first team lose, second team win
	{
		--record[firstTeam][2];
		--record[secondTeam][0];
		if (CheckPlay(round + 1)) return true;
		++record[firstTeam][2];
		++record[secondTeam][0];
	}

	return false;
}

void Solve()
{
	record.assign(6, vector<int>(3, 0));
	t = 4;

	while (t--)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> record[i][j];
			}
		}

		if (CheckPlay(0)) cout << 1 << " ";
		else cout << 0 << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}