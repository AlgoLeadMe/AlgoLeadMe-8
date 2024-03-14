#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_INT = 9999999;	

int N, K;
pair<int, int> visited[100001];
queue<int> q;		// ���� �̵��ؾ��� ĭ���� BFS�� �湮�ϱ� ���ؼ� ť�� ����
stack<int> st;	// ������(K)���� ��Ʈ��ŷ�� ���� �����(N)���� �湮�ߴ� ������ �־� ������� ����ϱ� ���� ������ ����

bool Check(int index)
{	// �̵��� �� �ִ� �� ����( 0 <= x <= 100,000 )�� ����� �ȵȴ�!
	if (index < 0 || index > 100000) return false;
	return true;
}

void Init()
{	// ������(N : �����)�� ����(K : ������) �� ����
	cin >> N >> K;
	// 0 ��° �ε����� ������ ���ϱ� ������ MAX_INT�� �ʱ�ȭ ���ش�.
	// ù��° ���� �ش� ��ȣ�� �湮�ϱ� ������ ��ȣ�� �����ϰ�, �ι�° ���� �ش� ��ȣ�� ��������� Ƚ���� �����Ѵ�.
	for (int i = 0; i < 100001; i++)
	{
		visited[i] = { MAX_INT, MAX_INT };
	}
	// ��� ������ 0�� Ƚ���� ä���ֱ�
	visited[N] = { N, 0 };
}

void Solve()
{	// 3������ ����� ��
	if (N == K)	// 1. ����(N)�� ����(K)�� ���� ��ġ�� ���� ��� �̵��ϴ� ĭ�� 0�̰� �ش� ��ġ�� �ٷ� ������ش�.
	{
		cout << visited[N].second << "\n" << N;
		return;
	}
	else if (N > K)	// 2. ����(N)�� ����(K)���� ū ��� K�� �����ϴ� ������ -1 �ۿ� ���� ������ -1�θ� ����� ������ ������ش�.
	{
		cout << N-K << "\n";
		while (N != K)
		{
			cout << N << " ";
			N--;
		}
		cout << N << "\n";
		return;
	}
	else// if(N < K)		// 3. ����(N)�� ����(K)���� ���� ��� +1, *2 �Ӹ� �ƴ϶� -1 * 2�� ���� ������ ��� ������ �ִ�. ex) 5���� 8�� �� ��� (1) 5 -> 4 -> 8 (2) 5 -> 10 -> 9 -> 4
	{	
		// ������(N: �����) ���� �־��ش�.
		q.push(N);

		while (!q.empty())
		{	// ���� �������� ��ġ�� ť���� �����ش�.
			int cur_num = q.front();
			q.pop();
			// ���� �̵��� ĭ�� ���� ���� �̵��� ���� ���� ��ġ ���� ������ �������� �������ش�.
			int cur_cnt, next_num;
			cur_cnt = visited[cur_num].second;
			// ���� ��ġ���� -1��ŭ �̵����� ���.
			next_num = cur_num - 1;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
			// ���� ��ġ���� +1��ŭ �̵����� ���.
			next_num = cur_num + 1;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
			// ���� ��ġ���� *2��ŭ �̵����� ���.
			next_num = 2 * cur_num;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
		}
		// ��������� ���������� ���µ� �ɸ� ĭ�� ��
		cout << visited[K].second << "\n";
		// ���������� ��������� �湮�ߴ� ������ �����Ͽ� ��� �����Ҷ��� K->N������ ����Ҷ��� N->K�� ����� ��!
		do {
			st.push(K);
			K = visited[K].first;
		} while (K != N);
		st.push(N);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Init();
	Solve();

	return 0;
}