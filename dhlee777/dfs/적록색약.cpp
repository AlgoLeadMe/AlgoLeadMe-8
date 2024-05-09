#include<iostream>
using namespace std;
char color[100][100];   //�������� ���� �׸�
char color2[100][100];    //���ϻ����� ���� �׸�
bool visited[100][100];   //������ �׸��� �湮����
bool visited2[100][100];  //���ϻ��� �׸��� �湮����
string line;             // ���� �Է��� �ޱ����� ��Ʈ��
int siz;                 //�׸��� �� ���� ����
int coun = 0;            //�������� �׸��������� �����ǰ���
int coun2 = 0;           //���ϻ����� ������ �����ǰ���
int x[4]={0,0,-1,1};     //�����¿� Ž���� ���� x��ǥ �̵���
int y[4] = { -1,1,0,0 };  // y��ǥ �̵���

void dfs(int a,int b,char color[][100], bool visited[][100]) {   //x:Ž������ ��ǥ,y:Ž������ y��ǥ color:�������� Ž������ ���ϻ����� Ž������
	for (int i = 0; i < 4; i++) {
		int a2 = a + x[i];
		int b2 = b + y[i];
		if (a2 >= 0 && a2 < siz && b2 >= 0 && b2 < siz && !visited[a2][b2]&&color[a][b]==color[a2][b2]) {
			visited[a2][b2] = true;
			dfs(a2, b2,color,visited);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> siz;
	for (int i = 0; i < siz; i++) {          //color,clolor2�迭�� �׸��� �Է¹޾� �������ش�.
		cin >> line;
		for (int j = 0; j < siz; j++) {
			color[i][j] = line[j];
			if (line[j] == 'R') color2[i][j] = 'G';     //���ϻ����� ���� r�� g�� �� �ٲ㼭 �������ش�.
			else  color2[i][j] = line[j];
		}
	}

	for (int i = 0; i < siz; i++) {         //�������� Ž��
		for (int j = 0; j < siz; j++) {
			if (!visited[i][j]) {
				dfs(i,j,color,visited);
				coun++;
			}
		}
	}
	for (int i = 0; i < siz; i++) {      //���ϻ����� Ž��
		for (int j = 0; j < siz; j++) {
			if (!visited2[i][j]) {
				dfs(i, j, color2,visited2);
				coun2++;
			}
		}
	}
	cout << coun <<" "<< coun2;
	return 0;
}