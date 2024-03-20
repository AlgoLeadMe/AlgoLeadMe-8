#include <iostream>
#include <vector>

using namespace std;

int tomato[1000001] = {0, };
int dir[2] = {1, -1};
int total = 1, dimension = 0;
vector<int> len;
vector<int> redTomato[2];
bool curVector = false;

bool isin(int a) { return a >= 0 && a < total; }

int main() {
    for (int i = 0; i < 11; i++) {
        int t; cin >> t;
        if (t != 1) {
            len.push_back(t);
            total *= t;
            dimension++;
        }
    }

    int greenTomato = 0;
    for (int i = 0; i < total; i++) {
        cin >> tomato[i];

        if (!tomato[i]) greenTomato++;
        else if (tomato[i] == 1) 
            redTomato[curVector].push_back(i);
    }

    int day = 0;
    while (greenTomato > 0) {
        int lastGreenTomato = greenTomato;

        while (!redTomato[curVector].empty()) {
            int curPos = redTomato[curVector].back();
            redTomato[curVector].pop_back();

            int modular = total;
            for (int dim = dimension - 1; dim >= 0; dim--) {
                for (int v : dir) {
                    int pos = curPos + (modular / len[dim]* v);
                    
                    if (isin(pos) && (curPos / modular == pos / modular) && !tomato[pos]) {
                        tomato[pos] = 1;
                        redTomato[!curVector].push_back(pos);
                        greenTomato--;
                    }
                }

                modular /= len[dim];
            }
        }

        if (lastGreenTomato == greenTomato) {
            printf("-1\n");
            return 0;
        }

        curVector = !curVector;
        day++;
    }
    
    printf("%d\n", day);
}