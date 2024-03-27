
//*첫번째 풀이(bfs 이용)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>com_edge[101];    //컴퓨터간의 간선의 정보를 저장하는 이차원벡터
int visited[101];   //감염된 컴퓨터인지 확인하기위한 배열
queue<int> q;
int coun = 0;
void bfs(int a) {     //bfs 를 위한 함수
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		int com = q.front();
		q.pop();
		for (int i = 0; i < com_edge[com].size(); i++) {
			int com_linked = com_edge[com][i];
			if (!visited[com_linked])
			{
				q.push(com_linked);
				coun++;            //방문되지않은 연결된 컴퓨터일경우 카운트
				visited[com_linked] = 1;
			}
		}
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int com_num, edge, a, b;
	cin >> com_num >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		com_edge[a].push_back(b);
		com_edge[b].push_back(a);
	}
	bfs(1);
	cout << coun;
	return 0;
}



//* 두번째 풀이 (union-find 이용)
#include<iostream>
using namespace std;
int parent [101];      //어떤컴퓨터의 부모컴퓨터를 저장하는 배열
int find_parent(int a) {      //루트 컴퓨터를 찾는 함수
	if (a == parent[a]) return a;
	else return parent[a] = find_parent(parent[a]);

}
void add(int a, int b) {    //두개의 컴퓨터가 속한 각각의 집합을 합치는 함수
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int com_num, edge,a,b;       
	cin >> com_num >> edge;
	for (int i = 1; i <= com_num; i++) {   //제일처음 자신의 부모는 자신이기에 초기화해준다.
		parent[i] = i;
	}
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		add(a, b);
	}
	int coun = 0;
	for (int i = 1; i <= com_num; i++) {     // 어떤컴퓨터의 루트컴퓨터가 1이라면 1과 연결된 같은 집합이므로 숫자를 카운트한다.
		if (find_parent(i) == 1) coun++;
	}
	
	cout << coun-1;    //1번 컴퓨터에의해 감염된 컴퓨터의 수를 세는것이므로 1번컴퓨터를 제외해준다.
	return 0;
}

