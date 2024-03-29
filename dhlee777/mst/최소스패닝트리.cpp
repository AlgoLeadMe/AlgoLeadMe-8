#include<iostream>
#include<queue>
using namespace std;
int parent[10001];  //�θ��带 �������ִ� �迭
int sum, cnt = 0;
int v_num, e_num;
priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
//������ ����ġ�� ������������ ���ĵǴ� �켱����ť,ť�� ���Ҵ�pair(����ġ,����1,����2)�� �̷������.
int find_parent(int a) {   //� ����� ��Ʈ��带 ã�� �Լ�
	if (a == parent[a]) return a;
	else
		return parent[a] = find_parent(parent[a]);
}
void add(int a, int b) {     //�� ��尡 ���� ������ �����ִ� �Լ�
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
bool compare_union(int a, int b) {   //�� ��尡 ������������ �Ǻ����ִ� �Լ�
	a = find_parent(a);
	b = find_parent(b);
	return (a == b);
}
void find_min() {    //����ġ�� �ּڰ��� ����ϴ� �Լ�
	while (!q.empty()) {   //ť���� ������ ����ġ�� ���峷�� pair�� ������.(greedy)
		int v1 = q.top().second.first;      //����� ����1
		int v2 = q.top().second.second;    //����� ����2
		int eg = q.top().first;            //���� ����ġ
		q.pop();
		if (compare_union(v1, v2)) continue;    //���� �� ������ ���� ������ ��� ���ý� ����Ŭ�� �߻��ϹǷ� ���������ʰ� �ݺ��� �������
		else   //�� ������ �ٸ� �����ϰ��(�� ���� ����)
		{
			add(v1, v2);  //�� ���� �� ���� ���� ������ �����ش�.
			sum += eg;   // ����ġ�� �����ش�.
			cnt++;   //������ ī��Ʈ���ش�
		}
		if (cnt == v_num - 1) //���� ������ ���� ����-1 �̵Ǹ� �������� �� ����Ȱ��̹Ƿ� �ݺ��� ����
			break;

	}
	cout << sum;  //����ġ �� �� ���
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v1, v2, eg;    // ����1,����2,����ġ
	cin >> v_num >> e_num;
	for (int i = 0; i < e_num; i++) {   //���� ������ŭ �Է¹޴´�
		cin >> v1 >> v2 >> eg;
		q.push(make_pair(eg, make_pair(v1, v2)));    //pair(����ġ,����1,����2)�� ť�� �ִ´�. 
	}

	for (int i = 0; i < v_num; i++) {  //�ڱ��ڽ��� �θ� �ڱ��ڽ����� �ʱ�ȭ
		parent[i] = i;
	}
	find_min();
	return 0;
}