#include<stdio.h>
#include<iostream>
using namespace std;
int parent[1000001];          //����� �θ��带 �����ϴ� �迭 ,���������δ� �� ���� ��Ʈ��尡 ����ȴ�.
int find_parent(int a) {        //� ����� ��Ʈ��带 ã�� �Լ�
	if (a == parent[a])  return a;
	else  return parent[a]=find_parent(parent[a]);
}
void add (int a,int b) {     
	a = find_parent(a);      //a�� ��Ʈ ��带 ã��
	b = find_parent(b);		//b�� ��Ʈ��带 ã��
	if (a == b) return;     //�� ���� ��Ʈ��尡 ������ �̹� �������տ� �����Ƿ� �Լ� ����
	if (a < b) parent[b] = a;   //�� ���� ���� ��Ʈ�� �ȴ�.
	else parent[a] = b;
}
void compare(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) cout<<"yes\n";  //�μ��� ��Ʈ�� ������(��������) yes �ƴϸ� no ��� 
	else  cout<<"no\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num, calculate_num,a,b,c;
	cin >> num >> calculate_num;
	for (int j = 1; j <= num; j++) {
		parent[j] = j; //�ڽ��� ��Ʈ�� �ڽ��̹Ƿ� �ʱ�ȭ���ش�.
	}
	for (int i = 0; i < calculate_num; i++) {
		cin >> a >> b >> c;
		if (!a)  add(b, c);  //0�ϰ�� ������ �����̹Ƿ� �� ������ �����ش�.
		else  compare(b, c);  //1�ϰ�� �� ���� �������տ� �ִ��� ��
		
	}
	
	return 0;
}