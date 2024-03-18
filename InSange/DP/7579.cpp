#include <iostream>
#include <vector>

using namespace std;

vector<int> memory;	// DP ���� �޸�
vector<int> app;			// �� ���� ũ��
vector<int> cost;			// �� ��Ȱ���� ��� ���
int N, M, costSum;		//	N:����, M:�ʿ��� �޸�

void Input()
{
	costSum = 0;			// ��� �� ��Ȱ���� ��� �ִ� ũ��� �������ֱ� ���� 0���� �ʱ�ȭ
	cin >> N >> M;
	// N���� ũ�⸸ŭ �� ���� ũ�� �߰�
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		app.push_back(n);
	}
	// N���� ��Ȱ���� ��� ��� �߰�
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		cost.push_back(n);
		costSum += n;
	}
	//	DP ũ�⸦ ��� �� ��Ȱ���� �߻��� �� �ִ� ���� ũ�⸸ŭ 0���� �Ҵ��ؼ� �ʱ�ȭ���ش�.
	memory.assign(costSum+1, 0);
}

int Solve()
{
	for (int i = 0; i < N; i++)
	{	// �ִ� ��뿡�� 0���� Ž���� �ϸ鼭 ��� ���ɼ����� �ּ��� ���ɼ����� ���� ����������.
		// �̷��� �����ϰ� �Ǹ� �ּ��� ���(���� ��Ȱ��ȭ)�� ã���鼭 M���� ũ�ų� ���� �޸𸮾���� ������ �� �ִ�.
		for (int j = costSum; j >= 0; j--)
		{	// ���� ���(cost[i])���� ���� ���(j)�� �۴ٸ� �� �Ʒ��� �ִ� ���� �Ҵ� ������. �ٷ� Ż��.
			if (cost[i] > j) break;
			// (������ �����ص� �޸� ���)�� (���� ����� �� ������ ��� + ���� ���)�� ���Ͽ� �� ū �޸𸮷� ��ü���ش�.
			memory[j] = max(memory[j], memory[j - cost[i]] + app[i]);
		}
	}

	for (int i = 0; i <= costSum; i++)
	{	// �޸�(DP)�� �ε����� ��Ȱ���ϴ� ����� ũ�⸦ ��Ÿ����. 0->costSum�� ���ƺ��鼭 M���� ũ�ų� ����(���� ����) �ε����� ã�� ��ȯ�Ѵ�.
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