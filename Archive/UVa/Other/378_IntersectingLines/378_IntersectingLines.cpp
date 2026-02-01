#include <bits/stdc++.h>
#define EPS 1e-8
using namespace std;

struct point {
    double x,y;
    point() {x = y = 0;}
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
    double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0; l.c = -p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b*l2.c)/(l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--){
        line ls[2];
        point interception;
        double x1, y1, x2, y2;
        for (int i = 0; i < 2; ++i) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            pointsToLine(point(x1, y1), point(x2, y2), ls[i]);
        }
        if (areSame(ls[0], ls[1])) printf("LINE\n");
        else if (areParallel(ls[0], ls[1])) printf("NONE\n");
        else if (areIntersect(ls[0], ls[1], interception)) {
            printf("POINT %.2lf %.2lf\n", interception.x, interception.y);
        }
    }
    printf("END OF OUTPUT\n");
}