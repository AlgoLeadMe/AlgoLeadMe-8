#include <iostream>
#include <vector>

using namespace std;

vector<int> memory;	// DP 저장 메모리
vector<int> app;			// 앱 실행 크기
vector<int> cost;			// 앱 비활성시 드는 비용
int N, M, costSum;		//	N:개수, M:필요한 메모리

void Input()
{
	costSum = 0;			// 모든 앱 비활성시 드는 최대 크기로 설정해주기 위해 0으로 초기화
	cin >> N >> M;
	// N개의 크기만큼 앱 실행 크기 추가
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		app.push_back(n);
	}
	// N개의 비활성시 드는 비용 추가
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		cost.push_back(n);
		costSum += n;
	}
	//	DP 크기를 모든 앱 비활성시 발생할 수 있는 가능 크기만큼 0으로 할당해서 초기화해준다.
	memory.assign(costSum+1, 0);
}

int Solve()
{
	for (int i = 0; i < N; i++)
	{	// 최대 비용에서 0으로 탐색을 하면서 모든 가능성에서 최소의 가능성으로 점점 좁혀나간다.
		// 이렇게 진행하게 되면 최소의 비용(적은 비활성화)를 찾으면서 M보다 크거나 같은 메모리양들을 적재할 수 있다.
		for (int j = costSum; j >= 0; j--)
		{	// 현재 비용(cost[i])보다 남은 비용(j)이 작다면 그 아래의 있는 값도 할당 못해줌. 바로 탈출.
			if (cost[i] > j) break;
			// (현재의 저장해둔 메모리 비용)과 (현재 비용을 뺀 나머지 비용 + 현재 비용)을 비교하여 더 큰 메모리로 교체해준다.
			memory[j] = max(memory[j], memory[j - cost[i]] + app[i]);
		}
	}

	for (int i = 0; i <= costSum; i++)
	{	// 메모리(DP)의 인덱스는 비활성하는 비용의 크기를 나타낸다. 0->costSum을 돌아보면서 M보다 크거나 같은(조건 충족) 인덱스를 찾아 반환한다.
		if (memory[i] >= M) return i;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	cout <<  Solve();

	return 0;
}