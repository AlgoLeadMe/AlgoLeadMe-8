#include<iostream>
#include<queue>
using namespace std;
int dt[100001];  // �ð�(����)�� �����ϴ� �迭,�ε����� �����̰� �ִ� ��ġ�̴�.
int k[3] = { -1,1};  //-1,1�� ��ġ�̵��� �����ֱ����� �迭
queue<int>q;

void bfs(int start, int end) {
	q.push(start);     // ť�� ���� ó�� �������� ������ġ�� �ִ´�. 
	while (!q.empty()) {
		int c = q.front();  //ť���� ��ġ�� ������.
		q.pop();
		if (c == end) {    //ť���� ���� ��ġ�� ������ ��ġ�ϰ��
			cout << dt[end]; //������ ã�� ��ġ������ �ּҽð��� ���
			return;     
		}
		for (int i = 0; i < 2; i++) {     //c�� �����ִ� ��ġ�� ���캻��(-1,+1)
			int d = c + k[i];      // -1,+1 �� ��ġ�̵��� ���ذ��� d���ִ´�.
			if (d >= 0 && !dt[d] && d <= 100000) { // �湮���� ���� ��ġ�̸� Ž���� �����Ѵ�.
					dt[d] = dt[c] + 1;    //������ �����ϸ� ���Ž������ġ�� �ð��� ���� ��ġ�ǽð� +1�� ���ش�.
					q.push(d);  //bfs������ ť�� ��� Ž������ġ�� �ִ´�.
			}
		}
		if (c * 2 <= 100000 && !dt[c * 2]) { //*2�� ���� Ž���� ���
			dt[c * 2] = dt[c] + 1;   //-1,1�ǰ��� ����
			q.push(c * 2);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int start,end;  
	cin >> start >> end;  //�������� ������ġ��,������ ������ġ�� �Է¹޴´�.
	bfs(start, end);
	return 0;
}