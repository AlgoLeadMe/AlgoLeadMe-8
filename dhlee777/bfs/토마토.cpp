#include<iostream>
#include<queue>
using namespace std;
int tom[101][101][101];             //토마토의 상태를 저장하기위한 배열
int col, row, height;
int x[6] = { 0,0,-1,1,0,0 };
int y[6] = { -1,1,0,0,0,0 };
int z[6] = { 0,0,0,0,1,-1 };
struct tomato {                           //토마토의 좌표를 저장하기위한 구조체
	int x1;                //열
	int y1;					//행
	int z1;                 //높이
	tomato(int _x1, int _y1, int _z1) {
		x1 = _x1; y1 = _y1; z1 = _z1;

	}
};
queue<tomato>q;
void bfs() {
	while (!q.empty()) {
		tomato t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {      //탐색범위(상,하,좌,우,위,아래)
			int _x = t.x1 + x[i];
			int _y = t.y1 + y[i];
			int _z = t.z1 + z[i];
			if (_x < col && _x >= 0 && _y < row && _y >= 0 && _z < height && _z >= 0 && tom[_z][_y][_x] == 0) {
				tom[_z][_y][_x] = tom[t.z1][t.y1][t.x1] + 1;
				q.push(tomato(_x, _y, _z));

			}
		}


	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> col >> row >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				cin >> tom[i][j][k];
				if (tom[i][j][k] == 1)         //익은토마토가 들어있으면
					q.push(tomato(k, j, i));   //탐색시작점을위해 그 좌표를 큐에 넣는다.
			}
		}
	}

	bfs();                             //
	int sum = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (tom[i][j][k] == 0)     //bfs후 안익은토마토가 있다면 모두익지못하는 상황이므로  -1을 출력
				{
					cout << -1;
					return 0;
				}
				if (sum < tom[i][j][k]) sum = tom[i][j][k]; //bfs 후 걸린시간을 찾기위해 tom배열의 최대값을 찾아 sum에 저장하는과정

			}
		}
	}

	sum == 1 ? cout << 0 : cout << sum - 1;         

}