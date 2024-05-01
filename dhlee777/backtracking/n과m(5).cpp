#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num_size, picked_size;
int num[8];   //입력받은 숫자들을 저장하는 배열
bool visited[8];  //방문했는지 확인하기위한 배열
vector<int>v;  //숫자들을 순서대로 넣기위한 벡터
void dfs(int cnt, int vt) {  //cnt는 방문숫자 카운팅,vt는 현재 숫자를 나타낸다.
	if (cnt == picked_size) {  // 방문한 수와 입력받은 골라야하는 개수가 같은경우,dfs(3,2)일 경우 셋째자리수가 num[2]일때의 수열들을 리턴해주는 함수 

		for (auto k : v) {
			cout << k << " ";    //벡터에 있는 수열을 출력
		}
		cout << "\n";
	}
	for (int j = 0; j < num_size; j++) {  //조합이 아니라 수열이므로 인덱스0부터 탐색시작
		if (!visited[j]) {          //num[j]를 방문하지 않았다면
			visited[j] = true;      //방문 표시를 하여주고
			v.push_back(num[j]);  //벡터에 그 수를 넣어준다.
			dfs(cnt + 1, j);  //카운트를 올려주고 j로이동해 다시 탐색진행
			v.pop_back();     //탐색이 끝났다면 벡터끝에서 수 하나를 빼준다.
			visited[j] = false;  //다른 경우를위해 j를 방문안했다고 바꿔준다.
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
	sort(num, num + num_size);  //입력받은 수는 뒤죽박죽이므로 오름차순 정렬을 시켜준다.
	dfs(0, 0);
}