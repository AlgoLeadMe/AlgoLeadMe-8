#include<iostream>
using namespace std;
long long int stair_num[101][11];   //n번째자리에 m이왔을때 가능한 계단의수
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;    //첫째자리수는 0은 제외하고 어떤수가 오든 경우의수는 1이다.
	for (int j = 1; j <= 9; j++)
		stair_num[1][j] = 1;
	for (int i = 2; i <=num; i++) {     //어떤자리수가 0일경우 그전자리수는 1이어야한다.
		for (int j =0; j <10; j++) {
			if (!j) stair_num[i][j] = stair_num[i - 1][1];
			stair_num[i][j] = (stair_num[i - 1][j - 1] + stair_num[i - 1][j + 1])%1000000000;
		}
	}
	long long int sum = 0;
	for (int j = 0; j < 10; j++) {  //제일 마지막자리에 0~9 가 오는 경우의수들을 각각 다 더해준다.
		 sum += stair_num[num][j];
	}
	cout << sum%1000000000;
	return 0;
}