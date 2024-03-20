#include <iostream>
#include <vector>

using namespace std;

int tomato[1000001] = {0, };
int dir[2] = {1, -1};
int total = 1, dimension = 0;
vector<int> len;
vector<int> redTomato[2];
bool curVector = false;

// 연산 범위 체크
bool isin(int a) { return a >= 0 && a < total; }

int main() {
    // input
    for (int i = 0; i < 11; i++) {
        int t; cin >> t;
        if (t != 1) { // 차원 추가
            len.push_back(t);
            total *= t;
            dimension++;
        }
    }

    int greenTomato = 0;
    for (int i = 0; i < total; i++) {
        cin >> tomato[i];

        if (!tomato[i]) greenTomato++; // 안익은 토마토
        else if (tomato[i] == 1) 
            redTomato[curVector].push_back(i); // 익은 토마토는 벡터에 넣어서 저장
    }

    int day = 0;
    while (greenTomato > 0) { // 안익은 토마토가 있으면 루프
        int lastGreenTomato = greenTomato;

        while (!redTomato[curVector].empty()) {
            // 이전 순회에서 추가된 토마토만 순회
            int curPos = redTomato[curVector].back();
            redTomato[curVector].pop_back();

            int modular = total; // 각 차원 별 현재 값 연산용
            for (int dim = dimension - 1; dim >= 0; dim--) { // 차원 별 순회
                for (int v : dir) {
                    int pos = curPos + (modular / len[dim]* v); // 차원 값 고려해서 배열 상의 현재 위치
                    
                    // 토마토가 범위 안에 있고, 다른 차원을 넘지 않았고, 안익었으면 벡터에 추가 후 다음 순회에 사용
                    if (isin(pos) && (curPos / modular == pos / modular) && !tomato[pos]) {
                        tomato[pos] = 1;
                        redTomato[!curVector].push_back(pos);
                        greenTomato--;
                    }
                }

                modular /= len[dim];
            }
        }

        // 더 이상 변화가 없으면 -1 출력 후 종료
        if (lastGreenTomato == greenTomato) {
            printf("-1\n");
            return 0;
        }

        curVector = !curVector;
        day++;
    }
    
    printf("%d\n", day);
}