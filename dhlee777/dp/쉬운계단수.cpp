#include<iostream>
using namespace std;
long long int stair_num[101][11];   //n��°�ڸ��� m�̿����� ������ ����Ǽ�
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;    //ù°�ڸ����� 0�� �����ϰ� ����� ���� ����Ǽ��� 1�̴�.
	for (int j = 1; j <= 9; j++)
		stair_num[1][j] = 1;
	for (int i = 2; i <=num; i++) {     //��ڸ����� 0�ϰ�� �����ڸ����� 1�̾���Ѵ�.
		for (int j =0; j <10; j++) {
			if (!j) stair_num[i][j] = stair_num[i - 1][1];
			stair_num[i][j] = (stair_num[i - 1][j - 1] + stair_num[i - 1][j + 1])%1000000000;
		}
	}
	long long int sum = 0;
	for (int j = 0; j < 10; j++) {  //���� �������ڸ��� 0~9 �� ���� ����Ǽ����� ���� �� �����ش�.
		 sum += stair_num[num][j];
	}
	cout << sum%1000000000;
	return 0;
}