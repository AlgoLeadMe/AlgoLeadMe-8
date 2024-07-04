#include<iostream>
using namespace std;
int dp[1025][1025];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size, cnt, start_row, start_col, end_row, end_col,temp;
	cin >> size >> cnt;

	for (int i = 1; i <=size; i++) {
		for (int j = 1; j <=size; j++) {
			cin >> temp;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp;
		}
	}
	for (int k = 0; k < cnt; k++) {
		cin >> start_row >> start_col >> end_row >> end_col;
		cout << dp[end_row][end_col] - dp[start_row - 1][end_col] - dp[end_row][start_col - 1] + dp[start_row - 1][start_col - 1];
		cout << "\n";
	}

	return 0;
}