#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num_size, picked_size;
int num[8];   //�Է¹��� ���ڵ��� �����ϴ� �迭
bool visited[8];  //�湮�ߴ��� Ȯ���ϱ����� �迭
vector<int>v;  //���ڵ��� ������� �ֱ����� ����
void dfs(int cnt, int vt) {  //cnt�� �湮���� ī����,vt�� ���� ���ڸ� ��Ÿ����.
	if (cnt == picked_size) {  // �湮�� ���� �Է¹��� �����ϴ� ������ �������,dfs(3,2)�� ��� ��°�ڸ����� num[2]�϶��� �������� �������ִ� �Լ� 

		for (auto k : v) {
			cout << k << " ";    //���Ϳ� �ִ� ������ ���
		}
		cout << "\n";
	}
	for (int j = 0; j < num_size; j++) {  //������ �ƴ϶� �����̹Ƿ� �ε���0���� Ž������
		if (!visited[j]) {          //num[j]�� �湮���� �ʾҴٸ�
			visited[j] = true;      //�湮 ǥ�ø� �Ͽ��ְ�
			v.push_back(num[j]);  //���Ϳ� �� ���� �־��ش�.
			dfs(cnt + 1, j);  //ī��Ʈ�� �÷��ְ� j���̵��� �ٽ� Ž������
			v.pop_back();     //Ž���� �����ٸ� ���ͳ����� �� �ϳ��� ���ش�.
			visited[j] = false;  //�ٸ� ��츦���� j�� �湮���ߴٰ� �ٲ��ش�.
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> num_size >> picked_size;
	for (int i = 0; i < num_size; i++) {
		cin >> num[i];
	}
	sort(num, num + num_size);  //�Է¹��� ���� ���׹����̹Ƿ� �������� ������ �����ش�.
	dfs(0, 0);
}