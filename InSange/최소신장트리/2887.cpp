#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct planet
{
	int index;
	int x;
	int y;
	int z;
	planet(int _index, int _x, int _y, int _z)
	{
		index = _index;
		x = _x;
		y = _y;
		z = _z;
	}
};

struct edges
{
	int dist;
	int index1;
	int index2;
	edges(int _dist = 0, int _index1 = 0, int _index2 = 0)
	{
		dist = _dist;
		index1 = _index1;
		index2 = _index2;
	}
};

vector<planet> planets;
vector<planet> p_x;
vector<planet> p_y;
vector<planet> p_z;

bool cmp_x(const planet& a, const planet& b)
{
	if (a.x < b.x) return true;
	return false;
}

bool cmp_y(const planet& a, const planet& b)
{
	if (a.y < b.y) return true;
	return false;
}

bool cmp_z(const planet& a, const planet& b)
{
	if (a.z < b.z) return true;
	return false;
}

void Init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		planet p(i, x, y, z);
		planets.push_back(p);
	}

	p_x.assign(planets.begin(), planets.end());
	p_y.assign(planets.begin(), planets.end());
	p_z.assign(planets.begin(), planets.end());

	sort(p_x.begin(), p_x.end(), cmp_x);
	sort(p_y.begin(), p_y.end(), cmp_y);
	sort(p_z.begin(), p_z.end(), cmp_z);
}

void Solve()
{
	vector<vector<pair<int, int>>> dists;
	dists.assign(N, vector<pair<int, int>>());

	for (int i = 1; i < N; i++)
	{
		planet p1 = p_x[i - 1];
		planet p2 = p_x[i];
		int dist = min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) });
		dists[p1.index].push_back({ dist, p2.index });
		dists[p2.index].push_back({ dist, p1.index });

		p1 = p_y[i - 1];
		p2 = p_y[i];
		dist = min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) });
		dists[p1.index].push_back({ dist, p2.index });
		dists[p2.index].push_back({ dist, p1.index });

		p1 = p_z[i - 1];
		p2 = p_z[i];
		dist = min({ abs(p1.x - p2.x), abs(p1.y - p2.y), abs(p1.z - p2.z) });
		dists[p1.index].push_back({ dist, p2.index });
		dists[p2.index].push_back({ dist, p1.index });
	}

	vector<bool> visited;
	visited.assign(N, false);
	
	int cnt = 0;
	int answer = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;	
	pq.push({ 0,  0 });

	while (!pq.empty())
	{
		if (cnt == N) break;
		int dist =pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;
		visited[cur] = true;
		cnt++;
		answer += dist;

		for (pair<int, int> val : dists[cur])
		{
			int n_dist = val.first;
			int n_index = val.second;
			if (visited[n_index]) continue;
			pq.push({ n_dist, n_index });
		}
	}

	cout << answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();
	Solve();

	return 0;
}