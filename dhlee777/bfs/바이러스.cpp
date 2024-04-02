
//*ù��° Ǯ��(bfs �̿�)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>com_edge[101];    //��ǻ�Ͱ��� ������ ������ �����ϴ� ����������
int visited[101];   //������ ��ǻ������ Ȯ���ϱ����� �迭
queue<int> q;
int coun = 0;
void bfs(int a) {     //bfs �� ���� �Լ�
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int com = q.front();
		q.pop();
		for (int i = 0; i < com_edge[com].size(); i++) {
			int com_linked = com_edge[com][i];
			if (!visited[com_linked])
			{
				q.push(com_linked);
				coun++;            //�湮�������� ����� ��ǻ���ϰ�� ī��Ʈ
				visited[com_linked] = 1;
			}
		}
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int com_num, edge, a, b;
	cin >> com_num >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		com_edge[a].push_back(b);
		com_edge[b].push_back(a);
	}
	bfs(1);
	cout << coun;
	return 0;
}



//* �ι�° Ǯ�� (union-find �̿�)
#include<iostream>
using namespace std;
int parent [101];      //���ǻ���� �θ���ǻ�͸� �����ϴ� �迭
int find_parent(int a) {      //��Ʈ ��ǻ�͸� ã�� �Լ�
	if (a == parent[a]) return a;
	else return parent[a] = find_parent(parent[a]);

}
void add(int a, int b) {    //�ΰ��� ��ǻ�Ͱ� ���� ������ ������ ��ġ�� �Լ�
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int com_num, edge,a,b;       
	cin >> com_num >> edge;
	for (int i = 1; i <= com_num; i++) {   //����ó�� �ڽ��� �θ�� �ڽ��̱⿡ �ʱ�ȭ���ش�.
		parent[i] = i;
	}
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		add(a, b);
	}
	int coun = 0;
	for (int i = 1; i <= com_num; i++) {     // ���ǻ���� ��Ʈ��ǻ�Ͱ� 1�̶�� 1�� ����� ���� �����̹Ƿ� ���ڸ� ī��Ʈ�Ѵ�.
		if (find_parent(i) == 1) coun++;
	}
	
	cout << coun-1;    //1�� ��ǻ�Ϳ����� ������ ��ǻ���� ���� ���°��̹Ƿ� 1����ǻ�͸� �������ش�.
	return 0;
}

