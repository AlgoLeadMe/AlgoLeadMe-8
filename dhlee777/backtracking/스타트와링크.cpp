#include<iostream>
#include<vector>
using namespace std;
int stats[21][21];    //i,j가 같은팀일때 능력치
int visited[21];         //선수를 방문했다면 1 방문하지않았다면 0을 할당 
int total_num;        //전체 선수의 수
int start, link;    // start팀 능력치합,link팀 능력치합
int inf = 987654321;   //두 팀의 능력치 차를 나타내는 변수
void dfs(int cnt, int num) {   //cnt는 방문한 선수의 수,num은 현재선수
	if (cnt == (total_num / 2)) {      //방문한선수의 수가 전체선수의 절반이라면
		start = 0;
		link = 0;
		for (int i = 1; i <= total_num; i++) {
			for (int j = 1; j <= total_num; j++) {
				if (visited[i] && visited[j] )    //만약 i,j를 둘다 방문했다면 start팀에 둘의 시너지를더해준다
					start += stats[i][j];
			 else if (!visited[i] &&!visited[j]) {//i,j둘다 방문하지않았다면 link팀에 둘의 시너지를 더해준다.
					link += stats[i][j];
				}

			}
		}
		if (inf > abs(start - link))     //두팀의 능력치차가 그전팀의 능력치 차보다 작다면
			inf = abs(start - link);     //inf가 최소가 되도록 갱신해준다.

		return;

	}
	for ( int i = num; i < total_num; i++) {  //전에 확인했던 선수는 확인하지 않기위해 현재선수부터 시작 
		visited[i] = 1;            //현재선수에  방문표시,방문했다면 start팀이 된다.방문안했다면 link팀     
		dfs(cnt + 1, i + 1);
		visited[i] = 0;      //탐색이 끝난후 다시 방문되지않았다고 초기화해준다.
	}
}
int main(void) {
	cin >> total_num;
	for (int i = 1; i <= total_num; i++) {
		for (int j = 1; j <= total_num; j++) {
			cin >> stats[i][j];
		}
	}
	dfs(0, 1);     //카운트0,선수1부터 시작
	cout << inf;

	return 0;
}