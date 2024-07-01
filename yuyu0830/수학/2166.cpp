#include <iostream>
#include <vector>
#define MAX 99999999

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    Point(ll X, ll Y) : x(X), y(Y) {};
};

ll getArea(Point a, Point b) {
    ll square = abs((a.x - b.x) * min(abs(a.y), abs(b.y))) * 2;
    ll triangle = abs((a.x - b.x) * (a.y - b.y));

    return square + triangle;
}

vector<Point> v;

int main() {
    ll a, b, area = 0, mx = MAX, my = MAX;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(Point(a, b));

        mx = min(mx, a);
        my = min(my, b);
    }

    for (auto &p : v) {
        p.x -= mx;
        p.y -= my;
    }

    v.push_back(v[0]);

    for (int i = 0; i < n; i++) {
        Point cur = v[i];
        Point next = v[i + 1];

        area += getArea(cur, next) * (cur.x <= next.x ? 1 : -1);
    }

    printf("%.1f\n", abs((double) area / 2));
}