#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>v;                   //�迭�� ���ҵ��� ������ ����
string a,b,nm;                 //a-��ɾ���� ������ string, b-�迭�� ������ string
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,num,start_idx,end_idx;      //t-�׽�Ʈ���̽�����,num-�����ǰ���,start_idx-���� �ε���,end_idx-���ε���
	int r_cnt = 0;
	cin >> t;
	while (t--) {
		cin >> a>>num>>b;
		start_idx = 0; end_idx = num - 1;          
		r_cnt = 0;
		for (int i = 0; i <b.size(); i++) {
			if (b[i] == '[' || b[i] == ']')
				continue;
			else if (b[i] == ',')
			{
				v.push_back(stoi(nm));
				nm.clear();
			}
			else 
				nm = nm + b[i];
				
		}
		if(!nm.empty()) v.push_back(stoi(nm));
		nm.clear();

		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'R')
				r_cnt++;                
			else {                        //d�������Ұ��
				if (end_idx == -1)           //���ͳ��� ���Ұ� ���°��
				{
					r_cnt == 0;
					end_idx--;
					break;
				}
				if (r_cnt % 2) {       //r�� Ȧ������������� �����ε����� ���ε����� �ٲ��ش�.
					int temp = start_idx;
					start_idx = end_idx;
					end_idx = temp;
				}
				if (start_idx > end_idx)
					start_idx--;
				else if (end_idx > start_idx)
					start_idx++;
				else  end_idx = -1;  //�����ε����� ���ε����� ������쿡 ���Ҵ� �ϳ������ϹǷ� d�� �����Ұ�� ���Ͱ� ��Եȴ�.
				r_cnt = 0;
			}
		}
		if (r_cnt != 0 && end_idx > -1&&r_cnt%2==1) {     //���ϳ��� r�� �ð��  �� ���Ͱ� �ƴϰ� r�ǰ����� Ȧ���϶�
			int temp = start_idx;
			start_idx = end_idx;
			end_idx = temp;
		}
		
		if (end_idx == -2) cout << "error"<<"\n";
		else if (end_idx == -1) cout << "[]"<<"\n";
		else {
			cout << "[";
			if (start_idx >= end_idx) {
				for (int i =start_idx; i>end_idx; i--) {
					cout << v[i] << ",";
				}
				cout << v[end_idx]<<"]"<<"\n";
			}
			else {
				for (int i = start_idx; i < end_idx; i++) {
					cout << v[i] << ",";
				}
				cout << v[end_idx]<<"]"<<"\n";
			}

		}
	
		vector<int>().swap(v);            //�ٸ� �׽�Ʈ���̽��� ���� ���� �ʱ�ȭ

	}


}