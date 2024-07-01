#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num;
vector<bool> visited;
vector<int> v;
vector<int> answer;

void DFS(int cur, int start)
{
	if (visited[cur] == true)
	{
		if (start == cur) answer.push_back(start);
		return;
	}

	visited[cur] = true;
	DFS(v[cur], start);
	visited[cur] = false;
}

void Solve()
{
	cin >> N;

	N += 1;
	visited.assign(N, false);
	v.assign(N, 0);

	for (int i = 1; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i < N; i++)
	{
		DFS(i, i);
	}

	int asize = answer.size();
	cout << asize << "\n";

	for (int i = 0; i < asize; i++)
	{
		cout << answer[i] << "\n";
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}