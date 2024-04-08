#include<iostream>
#include<queue>
using namespace std;
int parent[10001];  //부모노드를 저장해주는 배열
int sum, cnt = 0;
int v_num, e_num;
priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
//간선의 가중치가 오름차순으로 정렬되는 우선순위큐,큐의 원소는pair(가중치,정점1,정점2)로 이루어진다.
int find_parent(int a) {   //어떤 노드의 루트노드를 찾는 함수
	if (a == parent[a]) return a;
	else
		return parent[a] = find_parent(parent[a]);
}
void add(int a, int b) {     //두 노드가 속한 집합을 합쳐주는 함수
	a = find_parent(a);
	b = find_parent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
bool compare_union(int a, int b) {   //두 노드가 같은집합인지 판별해주는 함수
	a = find_parent(a);
	b = find_parent(b);
	return (a == b);
}
void find_min() {    //가중치의 최솟값을 출력하는 함수
	while (!q.empty()) {   //큐에서 간선의 가중치가 가장낮은 pair를 꺼낸다.(greedy)
		int v1 = q.top().second.first;      //연결된 정점1
		int v2 = q.top().second.second;    //연결된 정점2
		int eg = q.top().first;            //간선 가중치
		q.pop();
		if (compare_union(v1, v2)) continue;    //꺼낸 두 정점이 같은 집합일 경우 선택시 사이클이 발생하므로 선택하지않고 반복문 계속진행
		else   //두 정점이 다른 집합일경우(그 간선 선택)
		{
			add(v1, v2);  //두 정점 이 각각 속한 집합을 합쳐준다.
			sum += eg;   // 가중치를 더해준다.
			cnt++;   //간선을 카운트해준다
		}
		if (cnt == v_num - 1) //만약 간선의 수가 정점-1 이되면 정점들이 다 연결된것이므로 반복문 종료
			break;

	}
	cout << sum;  //가중치 의 합 출력
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v1, v2, eg;    // 정점1,정점2,가중치
	cin >> v_num >> e_num;
	for (int i = 0; i < e_num; i++) {   //간선 개수만큼 입력받는다
		cin >> v1 >> v2 >> eg;
		q.push(make_pair(eg, make_pair(v1, v2)));    //pair(가중치,정점1,정점2)를 큐에 넣는다. 
	}

	for (int i = 0; i < v_num; i++) {  //자기자신의 부모를 자기자신으로 초기화
		parent[i] = i;
	}
	find_min();
	return 0;
}