#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>v;                   //배열의 원소들을 저장할 벡터
string a,b,nm;                 //a-명령어들을 저장할 string, b-배열을 저장할 string
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,num,start_idx,end_idx;      //t-테스트케이스개수,num-원소의개수,start_idx-시작 인덱스,end_idx-끝인덱스
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
			else {                        //d를실행할경우
				if (end_idx == -1)           //벡터내의 원소가 없는경우
				{
					r_cnt == 0;
					end_idx--;
					break;
				}
				if (r_cnt % 2) {       //r이 홀수번나왔을경우 시작인덱스와 끝인덱스를 바꿔준다.
					int temp = start_idx;
					start_idx = end_idx;
					end_idx = temp;
				}
				if (start_idx > end_idx)
					start_idx--;
				else if (end_idx > start_idx)
					start_idx++;
				else  end_idx = -1;  //시작인덱스와 끝인덱스가 같을경우에 원소는 하나존재하므로 d를 실행할경우 벡터가 비게된다.
				r_cnt = 0;
			}
		}
		if (r_cnt != 0 && end_idx > -1&&r_cnt%2==1) {     //제일끝에 r이 올경우  빈 벡터가 아니고 r의개수가 홀수일때
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
	
		vector<int>().swap(v);            //다른 테스트케이스를 위한 벡터 초기화

	}


}