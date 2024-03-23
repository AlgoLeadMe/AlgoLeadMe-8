#include<stdio.h>
#include<iostream>
using namespace std;
int parent[1000001];          //어떤수의 부모노드를 저장하는 배열 ,최종적으로는 그 수의 루트노드가 저장된다.
int find_parent(int a) {        //어떤 노드의 루트노드를 찾는 함수
	if (a == parent[a])  return a;
	else  return parent[a]=find_parent(parent[a]);
}
void add (int a,int b) {     
	a = find_parent(a);      //a의 루트 노드를 찾고
	b = find_parent(b);		//b의 루트노드를 찾아
	if (a == b) return;     //두 수의 루트노드가 같으면 이미 같은집합에 있으므로 함수 종료
	if (a < b) parent[b] = a;   //더 작은 수가 루트가 된다.
	else parent[a] = b;
}
void compare(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) cout<<"yes\n";  //두수의 루트가 같으면(같은집합) yes 아니면 no 출력 
	else  cout<<"no\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num, calculate_num,a,b,c;
	cin >> num >> calculate_num;
	for (int j = 1; j <= num; j++) {
		parent[j] = j; //자신의 루트는 자신이므로 초기화해준다.
	}
	for (int i = 0; i < calculate_num; i++) {
		cin >> a >> b >> c;
		if (!a)  add(b, c);  //0일경우 합집합 연산이므로 두 집합을 합쳐준다.
		else  compare(b, c);  //1일경우 두 수가 같은집합에 있는지 비교
		
	}
	
	return 0;
}