#include <iostream>
#include <map>
#include <vector>

#define NUM 1000010
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

typedef pair<int, int> ii;

int cnt = 0;
int arr[NUM] = {0, };
vector<ii> v[NUM];

// 이진 탐색
int bs(int value) {
    int low = 0, mid, high = cnt;

    while (low <= high) {
        mid = (low + high) / 2;

        if (v[mid].back().first == value)
            return -1;

        if (value < v[mid].back().first) high = mid - 1;
        else low = mid + 1;
    }

    return mid + (value < v[mid].back().first ? -1 : 0);
}

int main() {
    fastio;

    int n; cin >> n;
    
    for (int i = 0; i < n; i++)  {
        cin >> arr[i];
    }

    // 오류 대비 초기값
    v[0].push_back(make_pair(-1000000001, 0));

    for (int i = 0; i < n; i++) {
        int l = arr[i];

        if (l > v[cnt].back().first) {
            // 만약 가장 큰 값이면 맨 앞에 두기
            v[++cnt].push_back(make_pair(l, v[cnt - 1].size()));
            continue;
        } 
        
        // 중간에 들어가야하는 값이면 앞의 요소가 뭔지 저장한 뒤에 벡터에 보관
        int t = bs(l) + 1;
        if (t == 0) continue;

        v[t].push_back(make_pair(l < v[t].back().first ? l : v[t].back().first, v[t - 1].size()));
    }

    printf("%d\n", cnt);

    // 가장 끝 요소부터 역순으로 순서 찾아오기
    vector<int> ans;
    ii tmp = v[cnt--][0];
    
    do {
        ans.push_back(tmp.first);
        tmp = v[cnt][tmp.second - 1];
    } while(cnt--);

    while (!ans.empty()) {
        printf("%d ", ans.back());
        ans.pop_back();
    }
}