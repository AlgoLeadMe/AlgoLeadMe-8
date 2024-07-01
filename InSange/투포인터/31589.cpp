#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, l, r, lastDrink;
vector<int> wine;
bool isLeft = false;
long long answer = 0;

void Solve()
{
	cin >> N >> K;
	
	wine.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> wine[i];
	}

	sort(wine.begin(), wine.end());

	l = 0;
	r = N - 1;
	answer = 0;
	lastDrink = 0;

	while (K--)
	{
		if (isLeft == true)	// ¸À ¾ø´Â °Å
		{
			lastDrink = wine[l];
			l++;
		}
		else// if(isLeft == false)	// ¸À ÀÖ´Â °Å
		{
			answer += wine[r] - lastDrink;
			r--;
		}

		isLeft = (isLeft + 1) & 1;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}