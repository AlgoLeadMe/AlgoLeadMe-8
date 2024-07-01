#include <iostream>
#include <cmath>

#define YES printf("1\n")
#define NO printf("0\n")

#define ERR_RANGE 1e-8

using namespace std;

struct Point {
    double x, y;
    void v(int _x, int _y) {
        x = (double) _x;
        y = (double) _y;
    };

    bool operator==(const Point &a) {
        return (fabs(x - a.x) < ERR_RANGE) && (fabs(y - a.y) < ERR_RANGE);
    }
};

struct Line {
    Point a, b;
    double gradient = 0.f, intercept = 0.f;
    bool isInf = 0, isZero = 0;

    void set() {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        // order by x
        x1 < y1 ? a.v(x1, x2) : a.v(y1, y2);
        x1 < y1 ? b.v(y1, y2) : b.v(x1, x2);

        // if gradient is Zero
        if (fabs(a.y - b.y) < ERR_RANGE) isZero = 1;

        // if gradient is Infinite
        else if (fabs(a.x - b.x) < ERR_RANGE) {
            isInf = 1;
            intercept = a.x;
        }

        else {
            gradient = (a.y - b.y) / (a.x - b.x);
            intercept = a.y - gradient * a.x;
        }
    }

    bool isPointIn(Point p) {
        bool ex = (p.x + ERR_RANGE >= a.x) && (p.x - ERR_RANGE <= b.x);
        double sy = fmin(a.y, b.y), by = fmax(a.y, b.y);
        bool ey = (p.y + ERR_RANGE >= sy) && (p.y - ERR_RANGE <= by);

        return ex && ey;
    }

    void operator=(const Line &l) {
        a = l.a;
        b = l.b;
        gradient = l.gradient;
        intercept = l.intercept;
        isZero = l.isZero;
        isInf = l.isInf;
    }
};

bool overlapCheck(Line a, Line b) {
    if (a.a == b.a || a.b == b.a || a.a == b.b || a.b == b.b) {
        YES;
        return true;
    }

    if (a.isInf && b.isInf) {
        double asy = fmin(a.a.y, a.b.y), aby = fmax(a.a.y, a.b.y);
        double bsy = fmin(b.a.y, b.b.y), bby = fmax(b.a.y, b.b.y);
        (fabs(a.intercept - b.intercept) < ERR_RANGE) && ((asy <= bby) != (aby <= bsy)) ? YES : NO;
        return true;
    }

    if (a.isZero && b.isZero)  {
        (fabs(a.a.x - b.a.x) < ERR_RANGE) && ((a.a.x <= b.b.x) != (a.b.x <= b.a.x)) ? YES : NO;
        return true;
    }

    if (a.gradient && fabs(a.gradient - b.gradient) < ERR_RANGE) {
        ((a.a.x <= b.b.x) != (a.b.x <= b.a.x)) && (fabs(a.intercept - b.intercept) < ERR_RANGE) ? YES : NO;
        return true;
    }

    return false;
}

Point getIntersection(Line a, Line b) {
    Point ret;

    if (a.isInf || b.isInf) {
        Line i = a.isInf ? a : b;
        Line j = a.isInf ? b : a;

        ret.x = i.intercept;
        ret.y = j.isZero ? j.a.y : j.gradient * ret.x + j.intercept;
    }

    else if (a.isZero || b.isZero) {
        Line i = a.isZero ? a : b;
        Line j = a.isZero ? b : a;

        ret.y = i.a.y;
        ret.x = (ret.y - j.intercept) / j.gradient;
    }
    
    else {
        ret.x = -((a.intercept - b.intercept) / (a.gradient - b.gradient));
        ret.y = a.gradient * ret.x + a.intercept;
    }

    return ret;
}

int main() {
    Line a, b;

    a.set();
    b.set();

    //printf("a : (%.0f, %.0f), (%.0f, %.0f), %.3f, %.3f, %d, %d\n", a.a.x, a.a.y, a.b.x, a.b.y, a.gradient, a.intercept, a.isInf, a.isZero);
    //printf("b : (%.0f, %.0f), (%.0f, %.0f), %.3f, %.3f, %d, %d\n", b.a.x, b.a.y, b.b.x, b.b.y, b.gradient, b.intercept, b.isInf, b.isZero);
    
    // if two line's gradient is same
    if (overlapCheck(a, b)) return 0;

    Point p = getIntersection(a, b);

    //printf("intersecion point : %.3f, %.3f\n", p.x, p.y);

    // is intersection point on both line?
    a.isPointIn(p) && b.isPointIn(p) ? YES : NO;
}