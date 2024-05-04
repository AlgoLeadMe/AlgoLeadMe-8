#include<iostream>
#include<vector>
using namespace std;
int stats[21][21];    //i,j�� �������϶� �ɷ�ġ
int visited[21];         //������ �湮�ߴٸ� 1 �湮�����ʾҴٸ� 0�� �Ҵ� 
int total_num;        //��ü ������ ��
int start, link;    // start�� �ɷ�ġ��,link�� �ɷ�ġ��
int inf = 987654321;   //�� ���� �ɷ�ġ ���� ��Ÿ���� ����
void dfs(int cnt, int num) {   //cnt�� �湮�� ������ ��,num�� ���缱��
	if (cnt == (total_num / 2)) {      //�湮�Ѽ����� ���� ��ü������ �����̶��
		start = 0;
		link = 0;
		for (int i = 1; i <= total_num; i++) {
			for (int j = 1; j <= total_num; j++) {
				if (visited[i] && visited[j] )    //���� i,j�� �Ѵ� �湮�ߴٸ� start���� ���� �ó����������ش�
					start += stats[i][j];
			 else if (!visited[i] &&!visited[j]) {//i,j�Ѵ� �湮�����ʾҴٸ� link���� ���� �ó����� �����ش�.
					link += stats[i][j];
				}

			}
		}
		if (inf > abs(start - link))     //������ �ɷ�ġ���� �������� �ɷ�ġ ������ �۴ٸ�
			inf = abs(start - link);     //inf�� �ּҰ� �ǵ��� �������ش�.

		return;

	}
	for ( int i = num; i < total_num; i++) {  //���� Ȯ���ߴ� ������ Ȯ������ �ʱ����� ���缱������ ���� 
		visited[i] = 1;            //���缱����  �湮ǥ��,�湮�ߴٸ� start���� �ȴ�.�湮���ߴٸ� link��     
		dfs(cnt + 1, i + 1);
		visited[i] = 0;      //Ž���� ������ �ٽ� �湮�����ʾҴٰ� �ʱ�ȭ���ش�.
	}
}
int main(void) {
	cin >> total_num;
	for (int i = 1; i <= total_num; i++) {
		for (int j = 1; j <= total_num; j++) {
			cin >> stats[i][j];
		}
	}
	dfs(0, 1);     //ī��Ʈ0,����1���� ����
	cout << inf;

	return 0;
}