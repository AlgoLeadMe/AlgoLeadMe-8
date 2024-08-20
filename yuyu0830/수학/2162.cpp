#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    void set(int X, int Y) {
        x = X;
        y = Y;
    }

    bool operator== (const Point t) {
        return x == t.x && y == t.y;
    }
};

struct Line {
    Point a, b;

    void set(int x1, int y1, int x2, int y2) {
        bool e;

        // x가 작은 순, 같다면 y가 큰 순
        // 사분면에서 왼쪽 위 점을 우선
        if (x1 != x2) e = x1 < x2;
        else e = y1 > y2;
        
        a.x = e ? x1 : x2;
        a.y = e ? y1 : y2;
        b.x = e ? x2 : x1;
        b.y = e ? y2 : y1;
    }
};


// CCW
Line arr[3001];
bool visited[3001] = {0, };

int CCW(Point a, Point b, Point c) {
    int t1 = a.x * b.y + b.x * c.y + c.x * a.y;
    int t2 = a.y * b.x + b.y * c.x + c.y * a.x;

    int s = t1 - t2;

    if (s > 0) return 1;
    else if (!s) return 0;
    else return -1;
}

bool isIntersect(Line l1, Line l2) {
    Point p1 = l1.a;
    Point p2 = l1.b;
    Point p3 = l2.a;
    Point p4 = l2.b;

    if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) return true;

    int t1 = CCW(p1, p2, p3) * CCW(p1, p2, p4); // l1 기준
    int t2 = CCW(p3, p4, p1) * CCW(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재하면
    // 기울기가 0 혹은 무한인 경우 || 겹치는 경우
    if (!t1 && !t2) {
        bool x = (p1.x == p3.x && p2.x == p4.x) || (p1.x <= p4.x != p2.x <= p3.x);
        bool y = (p1.y == p3.y && p2.y == p4.y) || (p1.y >= p4.y != p2.y >= p3.y);

        return x && y;
    }

    return t1 <= 0 && t2 <= 0;
}

// union find
int parent[3001] = {0, };
int count[3001] = {0, };

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int x, int y) { 
    parent[find(min(x, y))] = find(max(x, y));
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr[i].set(a, b, c, d);

        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // i번째 Line는 0 ~ i - 1번째 Line까지 겹치는지 확인
            // 겹치면 Union 해버리기
            if (isIntersect(arr[i], arr[j])) 
                merge(i, j);
        }
    }
    
    // 겹침 여부가 뒤에 결정될 수도 있기 때문에 나중에 몰아서 개수 연산
    for (int i = 0; i < n; i++) 
        ::count[find(i)]++;

    int cnt = 0, maxCnt = 0;

    // 개수 갱신
    for (int i = 0; i < n; i++) {
        if (::count[i]) {
            cnt++;
            maxCnt = max(maxCnt, ::count[i]);
        } 
    }

    printf("%d\n%d\n", cnt, maxCnt);
}