#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, num, answer;
priority_queue < int> pq;
deque<int> logs;

void Solve()
{
	cin >> T;

	while (T--)
	{
		answer = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> num;
			pq.push(num);
		}

		bool isLeft = true;

		while (!pq.empty())
		{
			if (isLeft)	
				logs.push_front(pq.top());
			else //if(!isLeft)
				logs.push_back(pq.top());

			pq.pop();
			isLeft = (isLeft ? false : true);
		}

		int lsize = logs.size();

		for (int i = 0; i < lsize; i++)
		{
			int next = (i + 1) % lsize;
			answer = max(answer, abs(logs[i] - logs[next]));
		}

		cout << answer << "\n";;
		logs.clear();
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}