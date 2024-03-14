#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int MAX_INT = 9999999;	

int N, K;
pair<int, int> visited[100001];
queue<int> q;		// 현재 이동해야할 칸들을 BFS로 방문하기 위해서 큐를 선언
stack<int> st;	// 도착지(K)에서 백트래킹을 통해 출발지(N)까지 방문했던 점들을 넣어 순서대로 출력하기 위해 스택을 선언

bool Check(int index)
{	// 이동할 수 있는 점 범위( 0 <= x <= 100,000 )를 벗어나면 안된다!
	if (index < 0 || index > 100000) return false;
	return true;
}

void Init()
{	// 수빈이(N : 출발지)와 동생(K : 목적지) 값 설정
	cin >> N >> K;
	// 0 번째 인덱스도 범위에 속하기 때문에 MAX_INT로 초기화 해준다.
	// 첫번째 값은 해당 번호를 방문하기 이전의 번호를 저장하고, 두번째 값은 해당 번호로 오기까지의 횟수를 저장한다.
	for (int i = 0; i < 100001; i++)
	{
		visited[i] = { MAX_INT, MAX_INT };
	}
	// 출발 지점은 0번 횟수로 채워넣기
	visited[N] = { N, 0 };
}

void Solve()
{	// 3가지의 경우의 수
	if (N == K)	// 1. 수빈(N)과 동생(K)가 같은 위치에 있을 경우 이동하는 칸은 0이고 해당 위치를 바로 출력해준다.
	{
		cout << visited[N].second << "\n" << N;
		return;
	}
	else if (N > K)	// 2. 수빈(N)이 동생(K)보다 큰 경우 K로 감소하는 접근은 -1 밖에 없기 때문에 -1로만 계산한 값들을 출력해준다.
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
	else// if(N < K)		// 3. 수빈(N)이 동생(K)보다 작은 경우 +1, *2 뿐만 아니라 -1 * 2로 빠른 접근을 노려 볼수도 있다. ex) 5에서 8로 갈 경우 (1) 5 -> 4 -> 8 (2) 5 -> 10 -> 9 -> 4
	{	
		// 수빈이(N: 출발지) 값을 넣어준다.
		q.push(N);

		while (!q.empty())
		{	// 현재 수빈이의 위치를 큐에서 꺼내준다.
			int cur_num = q.front();
			q.pop();
			// 현재 이동한 칸의 수와 다음 이동할 점에 대한 위치 값을 저장할 변수들을 선언해준다.
			int cur_cnt, next_num;
			cur_cnt = visited[cur_num].second;
			// 현재 위치에서 -1만큼 이동했을 경우.
			next_num = cur_num - 1;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
			// 현재 위치에서 +1만큼 이동했을 경우.
			next_num = cur_num + 1;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
			// 현재 위치에서 *2만큼 이동했을 경우.
			next_num = 2 * cur_num;
			if (Check(next_num) && visited[next_num].second > cur_cnt + 1)
			{
				q.push(next_num);
				visited[next_num].first = cur_num;
				visited[next_num].second = cur_cnt + 1;
			}
			if (next_num == K) break;
		}
		// 출발지에서 도착지까지 가는데 걸린 칸의 수
		cout << visited[K].second << "\n";
		// 도착지에서 출발지까지 방문했던 점들을 저장하여 출력 저장할때는 K->N이지만 출력할때는 N->K로 출력이 됨!
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