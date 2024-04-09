#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 1999999999;

int N, num, minVal, aanswer, banswer;
vector<int> acid;	// »ê¼º
vector<int> basic;	// ¿°±â¼º

bool cmp(int a, int b)
{
	return a > b;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		(num > 0) ? acid.push_back(num) : basic.push_back(num);
	}

	sort(acid.begin(), acid.end());
	sort(basic.begin(), basic.end(), cmp);

	minVal = MAX_VAL;
}

void Solve()
{
	int a_index = 0;
	int b_index = 0;
	while (a_index < acid.size() && b_index < basic.size())
	{
		int anum, bnum;
		anum = acid[a_index];
		bnum = basic[b_index];

		if (abs(anum + bnum) < minVal)
		{
			aanswer = anum;
			banswer = bnum;
			minVal = abs(anum + bnum);
		}

		(abs(anum) > abs(bnum)) ? b_index++ : a_index++;
	}

	int sum;
	if (acid.size() > 1)
	{
		sum = abs(acid[0] + acid[1]);
		if (sum < minVal)
		{
			aanswer = acid[1];
			banswer = acid[0];
		}
	}
	if (basic.size() > 1)
	{
		sum = abs(basic[0] + basic[1]);
		if (sum < minVal)
		{
			aanswer = basic[0];
			banswer = basic[1];
		}
	}
	if (acid.empty())
	{
		aanswer = basic[0];
		banswer = basic[1];
	}
	if (basic.empty())
	{
		aanswer = acid[1];
		banswer = acid[0];
	}

	cout << banswer << " " << aanswer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Solve();

	return 0;
}