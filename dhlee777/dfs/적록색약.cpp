#include<iostream>
using namespace std;
char color[100][100];   //정상인이 보는 그림
char color2[100][100];    //적록색약이 보는 그림
bool visited[100][100];   //정상인 그림의 방문여부
bool visited2[100][100];  //적록색약 그림의 방문여부
string line;             // 한줄 입력을 받기위한 스트링
int siz;                 //그림의 한 변의 길이
int coun = 0;            //정상인이 그림을봤을때 구역의개수
int coun2 = 0;           //적록색약이 봤을때 구역의개수
int x[4]={0,0,-1,1};     //상하좌우 탐색을 위한 x좌표 이동값
int y[4] = { -1,1,0,0 };  // y좌표 이동값

void dfs(int a,int b,char color[][100], bool visited[][100]) {   //x:탐색시작 좌표,y:탐색시작 y좌표 color:정상인의 탐색인지 적록색약의 탐색인지
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
	for (int i = 0; i < siz; i++) {          //color,clolor2배열에 그림을 입력받아 저장해준다.
		cin >> line;
		for (int j = 0; j < siz; j++) {
			color[i][j] = line[j];
			if (line[j] == 'R') color2[i][j] = 'G';     //적록색약을 위해 r을 g로 다 바꿔서 저장해준다.
			else  color2[i][j] = line[j];
		}
	}

	for (int i = 0; i < siz; i++) {         //정상인의 탐색
		for (int j = 0; j < siz; j++) {
			if (!visited[i][j]) {
				dfs(i,j,color,visited);
				coun++;
			}
		}
	}
	for (int i = 0; i < siz; i++) {      //적록색약의 탐색
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