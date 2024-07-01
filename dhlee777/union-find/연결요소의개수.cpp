#include<iostream>
#include<set>
using namespace std;
int parent[1001];       
set<int>s;
int find_parent(int a) {
	if (parent[a] == a) return a;
	else  return parent[a]=find_parent(parent[a]);
}
void unionn(int a, int b) {
	int root_a = find_parent(a);
	int root_b = find_parent(b);
	if (a == b) return;
	if (root_a < root_b) parent[root_b] = root_a;
	else parent[root_a] = root_b;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e,v1,v2;
	cin >> v >> e;
	for (int j = 1; j <= v; j++) {
		parent[j] = j;
	}
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		unionn(v1, v2);
	}
	for (int i = 1; i <= v; i++) {
		int  v3=find_parent(i);
		s.insert(v3);
	}
	cout << s.size();
}