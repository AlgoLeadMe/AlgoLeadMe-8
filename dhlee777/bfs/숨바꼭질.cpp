#include<iostream>
#include<queue>
using namespace std;
int dt[100001];  // 시간(몇초)를 저장하는 배열,인덱스는 수빈이가 있는 위치이다.
int k[3] = { -1,1};  //-1,1의 위치이동을 더해주기위한 배열
queue<int>q;

void bfs(int start, int end) {
	q.push(start);     // 큐에 제일 처음 수빈이의 시작위치를 넣는다. 
	while (!q.empty()) {
		int c = q.front();  //큐에서 위치를 꺼낸다.
		q.pop();
		if (c == end) {    //큐에서 꺼낸 위치가 동생의 위치일경우
			cout << dt[end]; //동생을 찾은 위치에서의 최소시간을 출력
			return;     
		}
		for (int i = 0; i < 2; i++) {     //c가 갈수있는 위치를 살펴본다(-1,+1)
			int d = c + k[i];      // -1,+1 의 위치이동을 해준값을 d에넣는다.
			if (d >= 0 && !dt[d] && d <= 100000) { // 방문하지 않은 위치이면 탐색을 진행한다.
					dt[d] = dt[c] + 1;    //조건을 만족하면 방금탐색한위치의 시간을 그전 위치의시간 +1을 해준다.
					q.push(d);  //bfs를위해 큐에 방금 탐색한위치를 넣는다.
			}
		}
		if (c * 2 <= 100000 && !dt[c * 2]) { //*2를 통한 탐색의 경우
			dt[c * 2] = dt[c] + 1;   //-1,1의경우와 동일
			q.push(c * 2);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int start,end;  
	cin >> start >> end;  //수빈이의 현재위치와,동생의 현재위치를 입력받는다.
	bfs(start, end);
	return 0;
}